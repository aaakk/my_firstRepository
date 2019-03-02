/*
 * singleton.cpp
 *
 *  Created on: 2018Äê9ÔÂ26ÈÕ
 *      Author: liangyj
 */

#include "singleton.h"

NS_LIANG_BEG

Singleton::Singleton()
{

}

Singleton* Singleton::instance = new Singleton();
Singleton* Singleton::getInstance()
{
	return instance;
}

NS_LIANG_END
