#include "algo/QuickSort.h"
#include "gtest/gtest.h"
#include "ftport.h"

namespace
{
   class testQuickSort : public testing::Test
   {
   };
}

FT_LIANG_BEG

TEST_F(testQuickSort, test_quick_sort)
{
    vector<int> array = {8,5,5,4,3,19,-3,2};
    QuickSort a(array);
    vector<int> expect = {-3,2,3,4,5,5,8,19};
    for(int i = 0; i < array.size(); i++)
    {
        ASSERT_TRUE(array[i] == expect[i]);
    }

};

FT_LIANG_END