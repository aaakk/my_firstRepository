#include "gtest/gtest.h"
#include <iostream>

namespace
{
   class testBase : public testing::Test
   {
   };
}

FT_LIANG_BEG

TEST_F(testBase, test_base)
{
    if(IsBaseType<U8>::isBaseType())
    {
        std::cout << "Is baseType" << std::endl;
    }

    if(!IsBaseType<float>::isBaseType())
    {
        std::cout << "Is baseType" << std::endl;
    }
}

FT_LIANG_END