#include <mutex>
#include <condition_variable>
#include <deque>

template<typename T>
struct BoundedBlockingQue
{
public:
    BoundedBlockingQue(int maxSize = 100):maxSize(maxSize){}

    bool size()
    {
        std::unique_lock<std::mutex> lk(mut);
        que.size();
    }

    bool isFull()
    {
        return maxSize > 0 && que.size() >= maxSize;
    }

    void put(T t)
    {
        std::unique_lock<std::mutex> lk(mut);
        notFull.wait(lk, [this](){return !isFull();});
        que.push_front(t);
        notEmpty.notify_one();
    }

    T take()
    {
        std::unique_lock<std::mutex> lk(mut);
        notEmpty.wait(lk, [this](){return !que.empty();});
        T front(std::move(que.front()));
        que.pop_front();
        notFull.notify_one();
        return front;
     }

private:
    int maxSize;
    std::mutex mut;
    std::condition_variable notEmpty;
    std::condition_variable notFull;
    std::deque<T> que;
};