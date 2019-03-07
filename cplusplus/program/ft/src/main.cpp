/*
 * main.cpp
 *
 *  Created on: 2019��2��28��
 *      Author: liangyj
 */

#include <iostream>
#include "port.h"
#include "TestArray.h"


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
    FT_LIANG(NullPointerA)* a =nullptr;
    a->Func1();
    a->Func2();


	return 0;
}

