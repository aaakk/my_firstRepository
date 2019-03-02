/*
 * port.h
 *
 *  Created on: 2019年2月28日
 *      Author: liangyj
 */

#ifndef CODE_INC_PORT_H_
#define CODE_INC_PORT_H_

//命名空间定义和使用
#define NS_LIANG_BEG namespace liang{
#define NS_LIANG_END }

#define USING_NS_LIANG  using namespace liang;

#define NS_LIANG(name) liang::name

//禁止复制构造函数的使用
#define NOT_ALLOW_COPY(ClassName)          \
	ClassName(const ClassName&) = delete;  \
	ClassName & operator =(const ClassName &) = delete

#endif /* CODE_INC_PORT_H_ */
