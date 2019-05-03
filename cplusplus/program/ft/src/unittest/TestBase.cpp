#include "gtest/gtest.h"
#include "ftport.h"
#include "Base.h"
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
    USING_NS_LIANG;

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