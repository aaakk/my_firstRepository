#pragma once

#include "nsport.h"
#include <string>

using std::string;

NS_LIANG_BEG

template<typename T>
inline T const& min(T const& a, T const& b)
{
    return a < b ? a : b;
}

template<>
inline string const& min(string const& a, string const& b)
{
    
    return a[0] < b[0] ? a : b;
}

NS_LIANG_BEG