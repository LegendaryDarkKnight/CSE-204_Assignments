#ifndef queuearr
#define queuearr

#include"Queue.hpp"
template<class var>
class QueueArr: public Queue<var>
{
    MyList<var> *list;
    public:
    QueueArr()
    {
        list=new Arr<var>;//#
    }
    QueueArr(int c)
    {
        list=new Arr<var>(c);
    }
    ~QueueArr()
    {
        list->clear();
        delete list;
    }
     void clear(){
        list->clear();
    }
     void enqueue(var item){
        list->pushBack(item);
    }
    var dequeue(){
        list->setToBegin();
        return list->erase();
    }
    int length(){ return list->size();}
    var frontValue(){
        list->setToBegin();
        return list->getValue();
    }
     var rearValue(){
        list->setToEnd();
        return list->getValue();
    }
    void show()
    {
        list->setToBegin();
        cout<<*list;
    }
    var leaveQueue()
    {
        list->setToEnd();
        return list->erase();
    }
};
template<class var>
class QueueLL: public Queue<var>
{
    MyList<var> *list;
    public:
    QueueLL()
    {
        list=new LL<var>();
    }
    QueueLL(int c)
    {
        list=new LL<var>(c);
    }
    ~QueueLL()
    {
        list->clear();
        delete list;
    }
     void clear(){
        list->clear();
    }
     void enqueue(var item){
        list->pushBack(item);
    }
    var dequeue(){
        list->setToBegin();
        return list->erase();
    }
    int length(){ return list->size();}
    var frontValue(){
        list->setToBegin();
        return list->getValue();
    }
    var rearValue(){
        list->setToEnd();
        return list->getValue();
    }
    void show()
    {
        list->setToBegin();
        cout<<*list;
    }
    var leaveQueue()
    {
        list->setToEnd();
        return list->erase();
    }
};
#endif