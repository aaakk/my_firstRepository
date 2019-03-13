#ifndef CODE_INC_SYSTIME_H_
#define CODE_INC_SYSTIME_H_

#include "port.h"

NS_LIANG_BEG

class SysTime
{
public:
    SysTime();
    virtual ~SysTime();

    void reset();
    void record();
    void print();

private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int msecond;
};

NS_LIANG_END

#endif

