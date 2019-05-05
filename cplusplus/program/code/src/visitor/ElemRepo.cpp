#include "visitor/ElemRepo.h"
#include "visitor/ElemVisitor.h"

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
