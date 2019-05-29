#include <uapi/linux/ptrace.h>

typedef enum NodeTag
{
    T_Invalid = 0,
} NodeTag;

typedef struct Node
{
    u32 type;
} Node;

struct key_t
{
    Node *node;
};
BPF_HASH(counts, struct key_t);

int count(struct pt_regs *ctx) 
{
    if(!PT_REGS_PARM1(ctx))
        return 0;

    struct key_t key = {};
    u64 zero = 0, *val;

    bpf_probe_read(&key.node, sizeof(key.node), (void *)PT_REGS_PARM1(ctx));
    val = counts.lookup_or_init(&key, &zero);
    (*val)++;
    return 0;
}
