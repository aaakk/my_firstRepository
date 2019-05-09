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
    int Func1();
    {
        return 1 ;
    }

    std::string Func2();
    {
        return std::string("Run Func2");
    }

    int a{10};
};

FT_LIANG_END

#endif