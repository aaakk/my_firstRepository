/*
 * ElemVisitor.cpp
 *
 *  Created on: 2019年4月24日
 *      Author: liangyj
 */

#ifndef CODE_INC_VISITOR_ELEMVISITOR_CPP_
#define CODE_INC_VISITOR_ELEMVISITOR_CPP_

#include <string>

struct ElemVisitor
{
    virtual ~ElemVisitor(){}

    virtual void visit(std::string& str) = 0;
};



#endif /* CODE_INC_VISITOR_ELEMVISITOR_CPP_ */
