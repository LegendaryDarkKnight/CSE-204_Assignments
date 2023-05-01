#ifndef stac1_E
#define stac1_E
#include "MyList_Arr.hpp"
#include "MyList_LL.hpp"
#include<iostream>
using namespace std;

template<class var>
class Stack
{
    public:
    virtual void clear()=0;
    virtual void push(var item)=0;
    virtual var pop()=0;
    virtual int length()=0;
    virtual var topValue()=0;
    virtual void show()=0;
    virtual var front()=0;
};
#endif