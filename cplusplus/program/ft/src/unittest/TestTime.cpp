#include <unistd.h>
#include "gtest/gtest.h"
#include "ftport.h"
#include "systime/TimeInfo.h"
#include "systime/TimeReader.h"

namespace
{
    class TestTime : public testing::Test
    {
        
    };
}

FT_LIANG_BEG

TEST_F(TestTime, test_time)
{
    NS_LIANG(TIMER).ROLE(TimeReader).readCurTime();
    sleep(5);
    NS_LIANG(TIMER).ROLE(TimeReader).readCurTime();
};


FT_LIANG_END
