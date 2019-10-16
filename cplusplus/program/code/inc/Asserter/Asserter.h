#pragma once 

#define ASSERT_VALID(func, result, value) \
if(!result) \
{ \
    std::cout << strFile(__FLIE__) << ":" << __LINE__ << " " << #func << result << std::endl; \
    return value; \
}




