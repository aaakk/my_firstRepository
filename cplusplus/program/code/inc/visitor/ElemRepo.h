/*
 * ElemRepo.h
 *
 *  Created on: 2019年4月24日
 *      Author: liangyj
 */

#ifndef CODE_INC_VISITOR_ELEMREPO_H_
#define CODE_INC_VISITOR_ELEMREPO_H_

#include <list>
#include <string>

struct ElemVisitor;

struct ElemRepo
{
    using dataList  = std::list<std::string>;

    ElemRepo(dataList& other);
    virtual ~ElemRepo();

    void acceptAll(ElemVisitor& visitor);

private:
    dataList elemList;
};

#endif /* CODE_INC_VISITOR_ELEMREPO_H_ */
