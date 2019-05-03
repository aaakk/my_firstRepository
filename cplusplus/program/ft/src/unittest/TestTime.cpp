#include "ftport.h"
#include "SysTime.h"
#include "gtest/gtest.h"

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

};


FT_LIANG_END