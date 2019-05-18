#ifndef CODE_INC_TEMPLATE_PRITER
#define CODE_INC_TEMPLATE_PRITER

#include "nsport.h"

NS_LIANG_BEG

template<typename... Args> class Printer;

template<typename T, typename... Args>
class Printer<T, Args...>
{
public:
    void doPrint()
    {
        T::doPrint();
        Printer<Args...>::doPrint();
    } 
}

template<>
class Print<>
{
public:
    void doPrint(){}
}

NS_LIANG_END

#endif
