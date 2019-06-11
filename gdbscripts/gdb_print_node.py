class DumpNode(gdb.Command):
    """Dump PostgreSQL Node Structures"""

    def __init__ (self):
        super (DumpNode, self).__init__ ("dump_node",
                                        gdb.COMMAND_SUPPORT,
                                        gdb.COMPLETE_NONE, False)

    def invoke (self, arg, from_tty):
        arg_list = gdb.string_to_argv(arg)
        if len(arg_list) != 1:
            log("usage: print_node var", True)
            return

        node = arg_list[0]
        self.dump_node(node)

    def dump_node(self, node):
        parsetree = gdb.parse_and_eval('pretty_format_node_dump(nodeToString(%s))' % node)
        print(parsetree.string())

DumpNode()
