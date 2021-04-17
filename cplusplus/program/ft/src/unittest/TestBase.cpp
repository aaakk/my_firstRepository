#include <iostream>
#include "Base.h"
#include "ftport.h"
#include "gtest/gtest.h"

namespace
{
   class testBase : public testing::Test
   {
   };
}

FT_LIANG_BEG

TEST_F(testBase, test_base)
{
    USING_NS_LIANG;

    if(IsBaseType<U8>::isBaseType())
    {
        std::cout << "Is baseType" << std::endl;
    }

    if(!IsBaseType<float>::isBaseType())
    {
        std::cout << "Is not baseType" << std::endl;
    }
}

TEST_F(testBase, DISABLED_test_core_dump)
{
    USING_NS_LIANG;

    U8* ptr = nullptr;
    *ptr = 1;
}

FT_LIANG_END