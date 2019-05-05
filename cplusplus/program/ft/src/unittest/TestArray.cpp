#include <iostream>
#include "gtest/gtest.h"
#include "TestArray.h"

namespace
{
   class testArray : public testing::Test
   {
   };
}

FT_LIANG_BEG

void NullPointerA::Func1()
{
   std::cout << "1" ;
}

void NullPointerA::Func2()
{
   std::cout << "Run Func2!!" << std::endl;
}

TEST_F(testArray, test_array)
{
   std::cout << "Hello World!!!" << std::endl;
   TestArray aa;
   for(int i = 0; i < 3; i++)
   {
      printf("%d, ", aa.a[i]);
   }

   ENTER_LINE

   for(int i = 0; i < 3; i++)
   {
      printf("%u, ", aa.a[i]);
   }

   ENTER_LINE

   FT_LIANG(NullPointerA)* a = nullptr;

   a->Func1();

   a->Func2();

//    std::cout << a->a << std::endl;  //运行无法通过这一段代码;

   FT_LIANG(NullPointerA)* b = new FT_LIANG(NullPointerA);

   for(int i; i<1000; i++)

   {b->Func1();}

   b->Func2();

   std::cout << b->a << std::endl;

};

FT_LIANG_END