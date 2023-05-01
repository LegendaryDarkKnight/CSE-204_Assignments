#include<iostream>
#include "MyList_Arr.h"
#include "MyList_LL.h"
using namespace std;
int main()
{
    LL<char *> arr;
    arr.push("Somik");
    arr.push("das");
    cout<<arr;
    //cout<<arr.maxSize()<<endl;
    arr.pushBack("Gupta");
    arr.push("Helllo");
    arr.next();
    cout<<arr;
    LL<char *> arr2=arr;
    //cout<<arr.maxSize()<<endl;
    cout<<arr.erase()<<endl;
    cout<<arr;
    arr.setToEnd();
    arr.push("haluea");
    cout<<arr;
    
    cout<<arr.getValue()<<"hh"<<endl;
    cout<<arr.erase()<<endl;
    //cout<<arr.maxSize()<<endl;
    cout<<arr;
    cout<<arr.erase()<<endl;
    //cout<<arr.maxSize()<<endl;
    cout<<arr;
    cout<<arr.erase()<<endl;
    //cout<<arr.maxSize()<<endl;
    cout<<arr;
    arr.pushBack("dsa");
    arr.push("sda");
    cout<<arr;
    //cout<<arr.maxSize()<<endl;
    cout<<arr2;
    cout<<34<<endl;
    //cout<<arr2.maxSize()<<endl;
    arr2.push("sadd");
    cout<<arr2;
    //cout<<arr2.maxSize()<<endl;
    arr2.clear();
    cout<<arr2;
    //cout<<arr2.maxSize()<<endl;
    arr2.pushBack("sdsd");
    arr2.push("sdasd");
    arr2.next();
    arr2.push("sdsd");
    cout<<arr2;
    //cout<<arr2.maxSize();
    
    
}