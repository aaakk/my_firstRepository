#include "asn-struct.h"

template<typename MsgType>
struct Msg
{
    Msg(){msg.nocts = 0;};
    MsgType* getMsg() const
    {
        return (MsgType*)&msg;
    }
    MsgType msg;
};

template<typename MsgType, typename ElemType, int N>
struct AllocMsgMem : AllocMsgMem<MsgType, ElemType, N-1>
{
    void alloc()
    {
        AllocMsgMem<MsgType, ElemType, N-1>::alloc();
        Msg<MsgType>::msg.elem[Msg<MsgType>::msg.nocts++] = &elemMem;
    }

private:
    ElemType elemMem; 
};

template<typename MsgType, typename ElemType>
struct AllocMsgMem<MsgType, ElemType, 0> : Msg<MsgType>
{
    void alloc(){}
};

#define __ALLOCMSG(MSGTYPE, ELEMTYPE, N, msg) \
AllocMsgMem<MSGTYPE, ELEMTYPE, N> allocMsg;   \
allocMsg.alloc();                             \
msg = allocMsg.getMsg();
