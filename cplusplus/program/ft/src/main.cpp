/*
 * main.cpp
 *
 *  Created on: 2019��2��28��
 *      Author: liangyj
 */

#include <iostream>
#include "Base.h"
#include "TestArray.h"
#include "SysTime.h"

USING_NS_LIANG

int main()
{
    std::cout << "Hello World!!!" << std::endl;
    FT_LIANG(TestArray) aa;
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

    NS_LIANG(SysTime) t;
    t.printCurrentTime();
    FT_LIANG(NullPointerA)* b = new FT_LIANG(NullPointerA);
    for(int i; i<1000; i++)
    {b->Func1();}
    b->Func2();
    std::cout << b->a << std::endl;

    NS_LIANG(SysTime) m;
    m.printCurrentTime();

    if(IsBaseType<U8>::isBaseType())
    {
        std::cout << "Is baseType" << std::endl;
    }
    if(!IsBaseType<float>::isBaseType())
    {
        std::cout << "Is baseType" << std::endl;
    }



	return 0;
}

