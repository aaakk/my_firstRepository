#ifndef CODE_INC_SYSTIME_H_
#define CODE_INC_SYSTIME_H_

#include "nsport.h"
#include "singleton.h"

NS_LIANG_BEG

SINGLETON(SysTime)
{
public:
    initSysTime();

    void reset();
    void record();
    void printRecordTime();
    void printCurrentTime();

private:
    int year{0};
    int month{0};
    int day{0};
    int hour{0};
    int minute{0};
    int second{0};
    int msecond{0};
    int usecond{0};
};

NS_LIANG_END

#endif