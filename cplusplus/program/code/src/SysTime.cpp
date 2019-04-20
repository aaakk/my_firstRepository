/*
 * SysTime.cpp
 *
 *  Created on: 2019年3月13日
 *      Author: liangyj
 */

#include <sys/time.h>
#include <iostream>
#include <iomanip>
#include "SysTime.h"

NS_LIANG_BEG

SysTime::SysTime() : year(0), month(0), day(0), hour(0), minute(0), second(0)
{
}

SysTime::~SysTime()
{
}

void SysTime::record()
{
    time_t timeStamp = time(NULL);
    tm* sysTime= localtime(&timeStamp);
    year   = sysTime->tm_year + 1900;
    month  = sysTime->tm_mon  + 1;
    day    = sysTime->tm_mday;
    hour   = sysTime->tm_hour;
    minute = sysTime->tm_min;
    second = sysTime->tm_sec;

    timeval msecStamp;
    gettimeofday(&msecStamp, nullptr);
    msecond = msecStamp.tv_sec / 1000 % 1000;
    usecond = msecStamp.tv_usec % 1000;
}

void SysTime::printRecordTime()
{
    std::cout << year << "-" << std::setfill('0') << std::setw(2) << month << "-" << std::setw(2) << day <<" " \
            << std::setw(2) << hour << ":" << std::setw(2) << minute << ":" << std::setw(2) << second << ":" << \
            std::setw(3) << msecond << std::setw(3) << usecond << std::endl;
}

void SysTime::reset()
{
    year    = 0;
    month   = 0;
    day     = 0;
    hour    = 0;
    minute  = 0;
    second  = 0;
    msecond = 0;
}

void SysTime::printCurrentTime()
{
    record();
    printRecordTime();
    reset();
}

NS_LIANG_END
