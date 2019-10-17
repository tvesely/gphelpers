#include <uapi/linux/ptrace.h>
#include "postgres_types_6.x.x.h"

struct data_t {
    u32 pid;  // PID as in the userspace term (i.e. task->tgid in kernel)
    int sockfd;
    int srcPid;
    int srcListenerPort;

    int dstPid;
    int dstListenerPort;

    int sessionId;
    u32 icId;

    int recvSliceIndex;
    int sendSliceIndex;
    int srcContentId;
    int dstContentId;
};
BPF_PERF_OUTPUT(events);

int dump_motion_init(struct pt_regs *ctx)
{
    struct data_t data = {};
    struct MotionConn conn = {};
    struct icpkthdr pkthdr = {};

    data.pid = bpf_get_current_pid_tgid() >> 32;

    if(!PT_REGS_PARM2(ctx))
        return 0;

    bpf_probe_read(&conn, sizeof(MotionConn), (void *)PT_REGS_PARM2(ctx));
    data.sockfd = conn.sockfd;
    data.srcPid = conn.conn_info.srcPid;
    data.srcListenerPort = conn.conn_info.srcListenerPort;

    data.dstPid = conn.conn_info.dstPid;
    data.dstListenerPort = conn.conn_info.dstListenerPort;

    data.sessionId = conn.conn_info.sessionId;

    data.icId = conn.conn_info.sessionId;

    data.recvSliceIndex = conn.conn_info.recvSliceIndex;
    data.sendSliceIndex = conn.conn_info.sendSliceIndex;

    data.srcContentId = conn.conn_info.srcContentId;
    data.dstContentId = conn.conn_info.dstContentId;

    events.perf_submit(ctx, &data, sizeof(data));
    return 0;
}
