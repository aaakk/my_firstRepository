/*
 * singleton.h
 *
 *  Created on: 2018Äê9ÔÂ26ÈÕ
 *      Author: liangyj
 */

#ifndef CODE_INC_SINGLETON_H_
#define CODE_INC_SINGLETON_H_

#include "port.h"

NS_LIANG_BEG

class Singleton
{
public:
	static Singleton* getInstance();

private:
	Singleton();

	NOT_ALLOW_COPY(Singleton);

	static Singleton* instance;
};

NS_LIANG_END



#endif /* CODE_INC_SINGLETON_H_ */
