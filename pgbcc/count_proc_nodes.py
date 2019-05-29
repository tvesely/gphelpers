#!/usr/bin/python
#
# count_proc_nodes: Trace Postgres/GPDB proc node execution globally across
#                   a host.
#
# Borrows liberally from the examples from both elftools and bcc. Requires
# both software packages installed to run.

from __future__ import print_function
from bcc import BPF
from time import sleep
from elftools.elf.elffile import ELFFile

import argparse

def get_enum(filename, enum_name):
    #print("Finding enum: %s filename: %s" % (enum_name, filename))

    enum = {}

    with open(filename, 'rb') as f:
        elffile = ELFFile(f)

        if not elffile.has_dwarf_info():
            print('No dwarf info')
            return None

        dwarfinfo = elffile.get_dwarf_info()

        enum_die = find_enum(dwarfinfo, enum_name)

        if enum_die is None:
            return None

        for child in enum_die.iter_children():
            enum[child.attributes['DW_AT_const_value'].value] = child.get_full_path()

    return enum


def find_enum(dwarfinfo, enum_name):
    for compilation_unit in dwarfinfo.iter_CUs():
        # Get DWARF Information Entries (DIEs)
        for die in compilation_unit.iter_DIEs():
            try:
                if die.tag == 'DW_TAG_enumeration_type':
                    if die.get_full_path() == enum_name:
                        return die
            except KeyError:
                continue
    return None

parser = argparse.ArgumentParser(description='Count postgres execution nodes')
parser.add_argument('--executable', help='path to postgres binary',
                    default='/usr/local/gpdb/bin/postgres')
args = parser.parse_args()

name = args.executable

nodetag = get_enum(name, 'NodeTag')

b = BPF(src_file='./count_proc_nodes.c')
b.attach_uprobe(name=name, sym="ExecProcNode", fn_name="count");

try:
    sleep(99999999)
except KeyboardInterrupt:
    pass

print("%10s %s" % ("COUNT", "NODE"))

counts = b.get_table("counts")

for k, v in sorted(counts.items(), key=lambda counts: counts[1].value):
    if nodetag is not None:
        print(b"%10d \"%s\"" % (v.value, nodetag[k.node]))
    else:
        print(b"%10d \"%s\"" % (v.value, k.node))
