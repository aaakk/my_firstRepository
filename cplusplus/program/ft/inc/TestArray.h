#ifndef FT_INC_TESTARRAY_H_
#define FT_INC_TESTARRAY_H_

#include <ftport.h>

FT_LIANG_BEG

class TestArray
{
public:
    TestArray(){};
    virtual ~TestArray(){};

    unsigned char a[5] = {0xff, 0, 0x7f};
};

class NullPointerA
{
public:
    void Func1();
    void Func2();
    int a{10};
};

FT_LIANG_END

#endif