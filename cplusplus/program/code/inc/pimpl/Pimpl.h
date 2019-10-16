#ifndef CODE_INC_PIMPL_PIMPLH_
#define CODE_INC_PIMPL_PIMPLH_

template<typename T>
class Pimpl
{
    Pimpl(){}
    Pimpl(T other) : pimpl(new T(other)){}
    ~Pimpl()
    {
        reset();
    }

    T* operator &()
    {
        return pimpl.get();
    }

    T& operator *()
    {
        return *(this->pimpl);
    }

    void reset()
    {
        pimpl.reset();
    }

private:
    unique_ptr<T> pimpl;
    Pimpl(Pimpl) = delete;
    Pimpl(Pimpl&) = delete;
    Pimpl(Pimpl&&) = delete;
};