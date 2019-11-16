#include "asn-struct.h"

template<typename MsgType>
struct Msg
{
    MsgType* getMsg() const
    {
        return &msg;
    }
    MsgType msg;
}

template<typename MsgType, typename ElemType, int N>
struct AllocMsgMem : AllocMsgMem<MsgType, ElemType, N-1>
{
    void alloc()
    {
        AllocMsgMem<MsgType, ElemType, N-1>::alloc();
        msg.elem[msg.nocts - N] = elemMem; 
    }

private:
    ElemType elemMem; 
} 

template<typename MsgType, typename ElemType, 0>
struct AllocMsgMem : Msg<MsgType>
{
    void alloc(){}
}

#define __ALLOCMSG(MSGTYPE, ELEMTYPE, N, msg) AllocMsgMem<MSGTYPE, ELEMTYPE, N> allocMsg; \
                                              msg = allocMsg.getMsg();