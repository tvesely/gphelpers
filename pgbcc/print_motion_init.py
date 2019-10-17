#!/usr/bin/python
#
# print_motion_init.py: Trace GPDB motion init globally across a host.

from __future__ import print_function
from bcc import BPF
from time import sleep

import argparse

parser = argparse.ArgumentParser(description='Trace motion node initialization')
parser.add_argument('--executable', help='path to postgres binary', default='/usr/local/gpdb/bin/postgres')
parser.add_argument('--content', help='segment contentid', type=int, default=None)
parser.add_argument('--sessionid', help='sessionid', type=int, default=None)
parser.add_argument('--slice', help='slice', type=int, default=None)
args = parser.parse_args()

b = BPF(src_file='./print_motion_init.c')
b.attach_uprobe(name=args.executable, sym="connAddHash", fn_name="dump_motion_init");

def print_event(cpu, data, size):
    event = b["events"].event(data)

    if event.pid == event.dstPid:
        motion_type = 'RECEIVER'
        content = event.dstContentId
        sliceindex = event.recvSliceIndex
    else:
        motion_type = 'SENDER'
        content = event.srcContentId
        sliceindex = event.sendSliceIndex

    if event.sessionId != args.sessionid and args.sessionid != None:
        return

    if content != args.content and args.content != None:
        return

    if sliceindex != args.slice and args.slice != None:
        return

    print("%(PID)10s %(TYPE)10s %(CONTENT)10s %(SLICE)10s %(SRCPID)10s %(SRCLISTENERPORT)15s %(DSTPID)10s %(DSTLISTENERPORT)15s %(SESSIONID)10s %(SENDSLICE)10s %(RECVSLICE)10s %(SRCCONTENT)11s %(DESTCONTENT)12s" % {
            'PID': event.pid,
            'TYPE': motion_type,
            'CONTENT': content,
            'SLICE': sliceindex,
            'SRCPID': event.srcPid,
            'SRCLISTENERPORT': event.srcListenerPort,
            'DSTPID': event.dstPid,
            'DSTLISTENERPORT': event.dstListenerPort,
            'SESSIONID': event.sessionId,
            'SENDSLICE': event.sendSliceIndex,
            'RECVSLICE': event.recvSliceIndex,
            'SRCCONTENT': event.srcContentId,
            'DESTCONTENT': event.dstContentId,
        }
    )

print("%(PID)10s %(TYPE)10s %(CONTENT)10s %(SLICE)10s %(SRCPID)10s %(SRCLISTENERPORT)15s %(DSTPID)10s %(DSTLISTENERPORT)15s %(SESSIONID)10s %(SENDSLICE)10s %(RECVSLICE)10s %(SRCCONTENT)11s %(DESTCONTENT)12s" % {
        'PID': "PID",
        'TYPE': "TYPE",
        'CONTENT': 'CONTENT',
        'SLICE': 'SLICE',
        'SRCPID': "SRCPID",
        'SRCLISTENERPORT': "SRCLISTENERPORT",
        'DSTPID': "DSTPID",
        'DSTLISTENERPORT': "DSTLISTENERPORT",
        'SESSIONID': 'SESSIONID',
        'SENDSLICE': 'SENDSLICE',
        'RECVSLICE': 'RECVSLICE',
        'SRCCONTENT': 'SRCCONTENT',
        'DESTCONTENT': 'DESTCONTENT',
    }
)
b["events"].open_perf_buffer(print_event)
while 1:
    try:
        b.perf_buffer_poll()
    except KeyboardInterrupt:
        exit()
