#pragma once

struct structElem
{
    unsigned int element;
};

struct structList
{
    unsigned int nocts;
    structElem* elem[800];
};

using unsigned int = PageNum;

struct BookName
{
    unsigned int n;
    char bookName[20];
}

struct Book
{
    BookName name;
    PageNum pages; 
}

struct BookList
{
    unsigned int n;
    Book elem[10];
};

template<typename AsnList>
struct WrappedAsnList
{
    typedef decltype(AsnList.elem[0]) Elem;
    typedef decltype(AsnList.n)       Num;

    AsnList& list;

    WrappedAsnList(const AsnList& list) : list(list){}

    Elem* begin()
    {
        return &list.elem[0];
    }

    Elem* end()
    {
        return &list.elem[list.n];
    }

    template<typename Elem>
    struct Iterator
    {
        Iterator(Elem* elem):elemPtr(elem){}

        Iterator& operator++()
        {
            elemPtr += sizeof(Elem);
            return *this;
        }

        Iterator& operator++(int)
        {
            Elem* tempPtr = elemPtr;
            ++this;
            return tempPtr;
        }

        Elem& operator *()
        {
            return *elemPtr;
        }

        Elem* elemPtr;
    }
}

