#include <iostream>
#include <sys/time.h>
#include "systime/TimeManager.h"
#include <iomanip>

NS_LIANG_BEG

TimeManager::TimeManager()
{
    timeRepo.reset();
}

void TimeManager::readTime()
{
    std::cout << timeRepo.year << "-" << std::setfill('0') << std::setw(2) << timeRepo.month \
    << "-" << std::setw(2) << timeRepo.day <<" " << std::setw(2) << timeRepo.hour << ":" << 
    std::setw(2) << timeRepo.minute << ":" << std::setw(2) << timeRepo.second << ":" << \
    std::setw(3) << timeRepo.msecond << std::setw(3) << timeRepo.usecond << std::endl;
}

void TimeManager::recordTime()
{
    timeRepo.reset();
    time_t timeStamp = time(NULL);
    tm* timer= localtime(&timeStamp);
    timeRepo.year   = timer->tm_year + 1900;
    timeRepo.month  = timer->tm_mon  + 1;
    timeRepo.day    = timer->tm_mday;
    timeRepo.hour   = timer->tm_hour;
    timeRepo.minute = timer->tm_min;
    timeRepo.second = timer->tm_sec;

    timeval msecStamp;
    gettimeofday(&msecStamp, nullptr);
    timeRepo.msecond = msecStamp.tv_usec / 1000 % 1000;
    timeRepo.usecond = msecStamp.tv_usec % 1000;
}

void TimeManager::readCurTime()
{
    recordTime();
    readTime();
}

NS_LIANG_END
