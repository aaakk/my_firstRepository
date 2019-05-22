#include <unistd.h>
#include "gtest/gtest.h"
#include "ftport.h"
#include "SysTime.h"

namespace
{
    class TestTime : public testing::Test
    {
        
    };
}

FT_LIANG_BEG

TEST_F(TestTime, test_time)
{
    NS_LIANG(SysTimeIf)::getInstance()->printCurrentTime();
    sleep(5);
    NS_LIANG(SysTimeIf)::getInstance()->printCurrentTime();
};


FT_LIANG_END
