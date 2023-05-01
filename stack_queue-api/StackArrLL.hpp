#ifndef stackarrll
#define stackarrll

#include"Stack.hpp"
template<class var>
class StackArr:public Stack<var>
{
    MyList<var> *list;
    public:
    StackArr()
    {
        list=new Arr<var>;
    }
    StackArr(int c)
    {
        list=new Arr<var>(c);
    }
    ~StackArr()
    {
        list->clear();
        delete list;
    }
    void clear(){ list->clear();}
    void push(var item){ list->pushBack(item);}
    var pop()
    {
        //cout<<list->size()<<endl;
        //if(list->size()==0)
        //return -1;
        list->setToEnd();
        return list->erase();
    }
    int length(){return list->size();}
    var topValue()
    {
        list->setToEnd();
        return list->getValue();
    }
    void show()
    {
        list->setToEnd();
        cout<<*list;
    }
    var front()
    {
        list->setToBegin();
        return list->getValue();
    }
};
template<class var>
class StackLL:public Stack<var>
{
    MyList<var> *list;
    public:
    StackLL()
    {
        list=new LL<var>;
    }
    StackLL(int c)
    {
        list=new LL<var>(c);
    }
    ~StackLL()
    {
        list->clear();
        delete list;
    }
    void clear(){ list->clear();}
    void push(var item){ list->pushBack(item);}
    var pop()
    {
        //cout<<list->size()<<endl;
        list->setToEnd();
        return list->erase();
    }
    int length(){return list->size();}
    var topValue()
    {
        list->setToEnd();
        return list->getValue();
    }
    void show()
    {
        list->setToEnd();
        cout<<*list;
    }
    var front()
    {
        list->setToBegin();
        return list->getValue();
    }
};
#endif