#pragma once

#include "role.h"

NS_LIANG_BEG

class TimeReader;
class TimeRecorder;

DEFINE_ROLE(TimeInfo)
{
    USE_ROLE(TimeReader);
    USE_ROLE(TimeRecorder);
}

TimeInfo& getTimer();

#define TIMER getTimer()

NS_LIANG_END