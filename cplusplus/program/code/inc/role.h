#ifndef INCLUDE_ROLE_H_
#define INCLUDE_ROLE_H_

#include <nsport.h>

NS_LIANG_BEG

#define ROLE(role) get##role()
#define IMPL_ROLE(role) role& ROLE(role){return const_cast<role&>(static_cast<const role&>(*this)); }
#define USE_ROLE(role) virtual role& ROLE(role)  = 0
#define DEFINE_ROLE(role) struct role : Role

struct Role
{
	virtual ~Role(){}
};

NS_LIANG_END

#endif 
