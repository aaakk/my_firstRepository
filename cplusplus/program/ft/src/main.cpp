#include "gtest/gtest.h"
#include "HandleCrashSig.h"

int main(int argc, char* argv[])
{
    HandleCrashSig();
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); 
}

