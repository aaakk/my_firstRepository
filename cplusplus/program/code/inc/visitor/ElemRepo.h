#ifndef CODE_INC_VISITOR_ELEMREPO_H_
#define CODE_INC_VISITOR_ELEMREPO_H_

#include "nsport.h"
#include <list>
#include <string>

NS_LIANG_BEG

struct ElemVisitor;

struct ElemRepo
{
    using dataElem = std::string;
    using dataList = std::list<dataElem>;

    ElemRepo(dataList& other);
    virtual ~ElemRepo();

    void acceptAll(ElemVisitor& visitor);

private:
    dataList elemList;
};

NS_LIANG_END

#endif 
