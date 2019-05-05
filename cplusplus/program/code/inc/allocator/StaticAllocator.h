//静态分配器

#ifndef CODE_INC_STATICALLOCATOR_H_
#define CODE_INC_STATICALLOCATOR_H_

#include <string>
#include "StaticAllocator.h"

template<typename T, int N>
class StaticAllocator
{
    StaticAllocator():freeHead(nullptr),freeTail(nullptr),freeCnt(0)
    {
        for(int i = 0; i < N; i++)
        {
            freeElem(&element[i]);
        }
    }

    void free(T* p)
    {
        if(!p) return;
        freeElem(*(Element*)p);
    }

    T* alloc()
    {
        T* p = tryAlloc()?doAlloc():nullptr;
        return p;
    }

    int getFreeNum()
    {
        return freeCnt;
    }

private:

    bool tryAlloc()
    {
        return (!freeHead)?true:false;
    }

   void freeElem(Element& elem)
   {
       if(!freeHead)
       {
           freeHead = *elem;
       }
       else
       {
           freeTail->next = *elem;
       }

       freeTail = freeTail->next;
       freeTail->next = nullptr;
       freeCnt++;
   }

   T* doAlloc()
   {
       T* p = freeHead;
       if(!freeHead)
       {
           freeHead = freeHead->next;
       }
       freeCnt--;
       return p;
   }


private:
    union Element
    {
        char elem[sizeof(T)];
        Element* next;
    };
private:
    Element element[N];
    Element* freeHead;
    Element* freeTail;
    int freeCnt;
};

#endif 
