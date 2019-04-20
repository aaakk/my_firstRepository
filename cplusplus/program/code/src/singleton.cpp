/*
 * singleton.cpp
 *
 *  Created on: 2018��9��26��
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
