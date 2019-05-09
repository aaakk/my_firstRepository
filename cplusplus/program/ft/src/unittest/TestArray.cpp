#include <iostream>
#include "gtest/gtest.h"
#include "TestArray.h"

namespace
{
   class testArray : public testing::Test
   {
   public: 
      int getArrayElem(int i)
      {
         if(i < 3 || i >= 0)
         {
            return elemArray[i];
         }
         else return 0;  
      }
   private:
      elemArray[3] = {0xff, 0, 0x7f};
   };
}

TEST_F(testArray, test_array)
{
   TestArray aa;
   for(int i = 0; i < 3; i++)
   {
      ASSERT_TRUE(aa.a[i] == getArrayElem(i));
   }

   ENTER_LINE

   FT_LIANG(NullPointerA)* a = nullptr;

   ASSERT_TRUE(a->Func1() == 1);

   ASSERT_TRUE(a->Func2() == std::string("Run Func2"));

//    std::cout << a->a << std::endl;  //运行无法通过这一段代码;

};

FT_LIANG_END