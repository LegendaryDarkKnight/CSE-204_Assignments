#ifndef queue
#define queue
#include"MyList_Arr.hpp"
#include"MyList_LL.hpp"
template<class var>
class Queue
{
    public:
    virtual void clear()=0;
    virtual void enqueue(var item)=0;
    virtual var dequeue()=0;
    virtual int length()=0;
    virtual var frontValue()=0;
    virtual var rearValue()=0;
    virtual void show()=0;
    virtual var leaveQueue()=0;
};
#endif