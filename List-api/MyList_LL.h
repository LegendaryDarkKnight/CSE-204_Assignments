#ifndef LLHeader
#define LLHeader
//#include<iostream>
#include "MyList.h"
//using namespace std;
template <class var>
class Node
{
public:
    var value;
    Node *next;
    Node()
    {
        //value=0;
        next=NULL;
    }
    Node(var item)
    {
        value=item;
        next=NULL;
    }
};
template <class var>
class LL:public MyList<var>
{
    Node<var> *head, *tail, *curr;
    int curr_pos, total;
public:
    LL()
    {
        total=0;
        curr_pos=0;
        head=tail=curr=NULL;
    }
    LL(int n)
    {
        total=0;
        curr_pos=0;
        head=tail=curr=NULL;
    }
    LL(const LL<var> &l)//Time Complexity: O(total)
    {
        this->curr_pos=l.curr_pos;
        this->total=l.total;
        //int c=0;
        head=new Node<var>(l.head->value);
        Node<var> *i=l.head;
        Node<var> *j=head;
        if(l.head==l.curr)
            curr=head;
        while(i->next!=NULL)
        {
            j->next=new Node<var>(i->next->value);
            if(i==l.curr)
                curr=j;
            i=i->next;
            j=j->next;
        }
        tail=j;
        if(l.curr==l.tail)
            curr=tail;
    }
    ~LL()
    {
        Node<var> *temp=head;
        while(!temp)
        {
            temp=temp->next;
            delete head;
            head=temp;
        }
        curr_pos=0;
        total=0;
        head=tail=curr=NULL;
    }
    void setCurr(Node<var> *x)//only for test purpose
    {
        curr=x;
    }
    void clear()//time complexity=O(total)
    {
        Node<var> *temp=head;
        while(!temp)
        {
            temp=temp->next;
            delete head;
            head=temp;
        }
        curr_pos=0;
        total=0;
        head=tail=curr=NULL;
    }
    void pushBack(var item)//Time Complexity O(1)
    {
        total++;
        Node<var> *temp=new Node<var>;
        temp->value=item;
        temp->next=NULL;
        if(tail) tail->next=temp;
        tail=temp;
        if(!head){
            head=tail;
            curr=head;
            curr_pos=0;
        }
    }
    void push(var item)//Time Complexity=O(total) if the insertion is in the prev node of tail, else Time Complexity: O(1)
    {
        total++;
        Node<var> *temp=new Node<var>;
        temp->value=item;
        temp->next=NULL;
        if(!head) head=temp;
        if(!tail) tail=temp;
        if(!curr && !curr_pos)
        {
            curr=temp;
            return ;
        }
        if(curr==head)
        {
            temp->next=head;
            head=temp;
            curr=temp;
        }
        else if(curr==tail)
        {
            Node<var>*i=head;
            while(i->next!=tail)
            {
                i=i->next;
            }
            temp->next=tail;
            i->next=temp;
            curr=temp;
        }
        else if(curr==NULL)
        {
            Node<var>*i=head;
            while(i->next!=curr)
            {
                i=i->next;
            }
            i->next=temp;
            tail=temp;
            curr=tail;
        }
        else
        {
            Node<var>*i=head;
            while(i->next!=curr)
            {
                i=i->next;
            }
            temp->next=curr;
            i->next=temp;
            curr=temp;
        }
    }
    var erase()//Time Complexity: O(total) if deletion is done for the node of tail, else Time Complexity: O(1)
    {
        Node<var> *temp=curr;
        var x=curr->value;
        Node<var> *i;
        try
        {
            if(total==0)
            throw 1;
        }
        catch(int n)
        {
            cout<<"No elements left";
            return 0;
        }

        total--;

        if(curr==head)
        {
            head=curr->next;
            curr=head;
        }
        else if(curr==tail)
        {
            i=head;
            while(i->next!=tail)
            {
                i=i->next;
            }
            curr_pos--;
            tail=i;
            tail->next=NULL;
            curr=tail;
        }
        else
        {
            i=head;
            
            while(i->next!=curr)
                i=i->next;
            i->next=curr->next;
            curr=curr->next;
        }
            delete temp;
            return x;
    }
    void setToPos(int pos)//Time Complexity=O(total)
    {
        Node<var> *i=head;
        int x=0;
        while(x!=pos)
        {
            i=i->next;
            x++;
            if(i==NULL && x!=pos)
            {
                //cout<<"Not possible"<<endl;
                return;
            }
        }
        curr_pos=pos;
        curr=i;
    }
    void setToBegin()//Time Complexity=O(1)
    {
        curr_pos=0;
        curr=head;
    }
    void setToEnd()//Time Complexity=O(1)
    {
        curr_pos=total-1;
        curr=tail;
    }
    void prev()//Time Complexity=O(total)
    {
        Node<var> *i=head;

        if(curr_pos==0)
        {
            //cout<<"Already at top"<<endl;
            return ;
        }
        curr_pos--;
        while(i->next!=curr)
        {
            i=i->next;
        }
        curr=i;
    }
    void next()//Time Complexity=O(1)
    {
        Node<var> *i=head;

        if(curr_pos==total-1)
        {
            //cout<<"Already at top"<<endl;
            return ;
        }
        curr_pos++;
        curr=curr->next;
    }
    int currPos()//Time Complexity=O(1)
    {
        return curr_pos;
    }
    int size()//Time Complexity=O(1)
    {
        return total;
    }
    var getValue()//Time Complexity=O(1)
    {
        try{
            if(total==0)
            {
                throw 2;
            }
            if(curr==NULL)
            {
                throw 1;
            }
        }
        catch(int n)
        {
            if(n==1)
            {
                //cout<<"Error in current position"<<endl;
                return 0;
            }
            if(n==2)
            {
                //cout<<"Empty List"<<endl;
                return 0;
            }
        }
        return curr->value;
    }
    int find(var item)//Time Complexity=O(total)
    {
        try
        {
           if(total==0)
                throw 1;
            if(head == NULL || tail==NULL || curr==NULL)
                throw 2;
        }
        catch(int n)
        {
            if(n==1)
            {
                //cout<<"Empty Array"<<endl;
            }
            if(n==2)
            {
                //cout<<"Pointers are NULL"<<endl;
            }
            return -1;
        }
        Node<var> *i=head;
        int x=0;
        while(i!=tail)
        {
            if(i->value==item)
                return x;
            x++;
            i=i->next;
        }
        if(i->value==item)return x;
        return -1;
    }
    void show()//for test purpose
    {
        cout<<endl<<"<";
        Node<var> *i=head;
        while(i!=NULL)
        {
            if(i==curr)
                cout<<"|";
            cout<<i->value<<" ";
            i=i->next;
        }
        cout<<">"<<endl;
    }
    Node<var> *getHead()//for test purpose
    {
        return head;
    }
    Node<var> *getCurr()//for test purpose
    {
        return curr;
    }
};

#endif