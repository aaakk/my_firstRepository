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
        T t;
	t.doPrint();
        Printer<Args...> arg;
	arg.doPrint();
    } 
};

template<>
class Printer<>
{
public:
    void doPrint(){}
};

NS_LIANG_END

#endif
