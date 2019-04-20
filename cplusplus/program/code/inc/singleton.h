//单例模式

#ifndef CODE_INC_SINGLETON_H_
#define CODE_INC_SINGLETON_H_

#include <nsport.h>

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
