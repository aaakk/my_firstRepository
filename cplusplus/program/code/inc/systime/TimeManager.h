#pragma once

#include "systime/TimeReader.h"
#include "systime/TimeRecorder.h"
#include "systime/TimeRepo.h"

NS_LIANG_BEG

struct TimeManager : TimeReader, TimeRecorder
{
    TimeManager();

    void readTime() override;
    void recordTime() override;
    void readCurTime() override;

private:
    TimeRepo timeRepo;
};

NS_LIANG_END