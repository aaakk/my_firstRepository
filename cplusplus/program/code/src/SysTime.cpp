/*
 * SysTime.cpp
 *
 *  Created on: 2019年3月13日
 *      Author: liangyj
 */

#include <time.h>
#include <iostream>
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
}

void SysTime::printRecordTime()
{
    std::cout << year << "-" << month << "-" << day << " " << hour << ":" << minute << ":" << second << std::endl;
}

void SysTime::printCurrentTime()
{
    record();
    printRecordTime();
}

void SysTime::reset()
{
    year    = 0;
    month   = 0;
    day     = 0;
    hour    = 0;
    minute  = 0;
    second  = 0;
}


NS_LIANG_END
