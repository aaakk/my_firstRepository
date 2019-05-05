#ifndef CODE_INC_VISITOR_ELEMVISITOR_CPP_
#define CODE_INC_VISITOR_ELEMVISITOR_CPP_

#include <string>

struct ElemVisitor
{
    virtual ~ElemVisitor(){}

    virtual void visit(std::string& str) = 0;
};

#endif 