#include "visitor/ElemRepo.h"
#include "visitor/ElemVisitor.h"

NS_LIANG_BEG

ElemRepo::ElemRepo(dataList& other) : elemList(other)
{
}

ElemRepo::~ElemRepo()
{
}

void ElemRepo::acceptAll(ElemVisitor& visitor)
{
    for(auto& i : elemList)
    {
        visitor.visit(i);
    }
}

NS_LIANG_END
