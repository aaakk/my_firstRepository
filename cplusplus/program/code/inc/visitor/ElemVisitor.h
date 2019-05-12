#ifndef CODE_INC_VISITOR_ELEMVISITOR_CPP_
#define CODE_INC_VISITOR_ELEMVISITOR_CPP_

#include "nsport.h"
#include <string>

NS_LIANG_BEG

struct ElemRepo;

using dataElem = ElemRepo::dataElem;

struct ElemVisitor
{
    virtual ~ElemVisitor(){}

    virtual void visit(dataElem& elem) = 0;
};

NS_LIANG_END

#endif 