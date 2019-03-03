/*
 * TestArray.h
 *
 *  Created on: 2019年3月3日
 *      Author: liangyj
 */

#ifndef FT_INC_TESTARRAY_H_
#define FT_INC_TESTARRAY_H_

#include "port.h"

FT_LIANG_BEG

class TestArray
{
public:
    TestArray();
    virtual ~TestArray();

    unsigned char a[5] = {0xff, 0, 0x7f};

};

FT_LIANG_END

#endif /* FT_INC_TESTARRAY_H_ */
