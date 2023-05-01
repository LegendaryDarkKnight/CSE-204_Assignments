#ifndef AbstractHeader
#define AbstractHeader
#include<iostream>
using namespace std;
template <class var>
class MyList
{
public:
    virtual int size()=0;
    virtual void push(var item)=0;
    virtual void pushBack(var item)=0;
    virtual var erase()=0;
    virtual void setToBegin()=0;
    virtual void setToEnd()=0;
    virtual void prev()=0;
    virtual void next()=0;
    virtual void setToPos(int pos)=0;
    virtual int currPos()=0;
    virtual var getValue()=0;
    virtual int find(var item)=0;
    virtual void clear()=0;
    template<class var1>
    friend ostream &operator<<(ostream &out, MyList<var1> &l);
};
template <class var>
ostream &operator<<(ostream &out, MyList<var> &l)
{
    out << "<";
    int pos = l.currPos();
    l.setToBegin();
    int i = 0;
    while (i < l.size())
    {
        if (i == pos)
            out << "|";
        out << l.getValue() << " ";
        ++i;
        l.next();
    }
    out << ">" << endl;
    l.setToPos(pos);
    return out;
}
#endif