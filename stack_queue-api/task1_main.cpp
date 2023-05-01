#include "StackArrLL.hpp"
#include "QueueArrLL.hpp"
template<class var>
ostream &operator <<(ostream &out, Queue<var> &l)
{
    l.show();
    return out;
}
template<class var>
ostream &operator <<(ostream &out, Stack<var> &l)
{
    l.show();
    return out;
}
int main()
{
    freopen("test1.txt","r",stdin);
    freopen("test1_out.txt","w",stdout);
    int k, x, m, y, v, Q, ch, temp;
    cin>>k>>x;
    Queue<int> *queue_1=new QueueArr<int>(x);
    for(int i=1; i<=k; i++)
    {
        cin>>v;
        queue_1->enqueue(v);
    }
    cin>>m>>y;
    Stack<int> *stack_1=new StackArr<int>(y);
    for(int i=1; i<=m; i++)
    {
        cin>>v;
        stack_1->push(v);
    }
    cout<<*queue_1;
    cout<<*stack_1;
    cin>>Q;
    while(Q--)
    {
        cin>>ch;
        if(ch==1)
        {
            cin>>v;
            queue_1->clear();
            cout<<*queue_1;
            cout<<-1<<endl;
        }
        else if(ch==2)
        {
            cin>>v;
            queue_1->enqueue(v); 
            cout<<*queue_1;
            
            cout<<-1<<endl;            
        }
        else if(ch==3)
        {
            cin>>v;
            temp=queue_1->dequeue();
            cout<<*queue_1;
            cout<<temp<<endl;
        }
        else if(ch==4)
        {
            cin>>v;
            cout<<*queue_1;
            cout<<queue_1->length()<<endl;
        }
        else if(ch==5)
        {  
            cin>>v;
            cout<<*queue_1;
            cout<<queue_1->frontValue()<<endl;
        }
        else if(ch==6)
        {
            cin>>v;
            cout<<*queue_1;
            cout<<queue_1->rearValue()<<endl;
        }
        else if(ch==7)
        {
            cin>>v;
            temp=queue_1->leaveQueue();
            cout<<*queue_1;
            cout<<temp<<endl;
        }
        else if(ch==8)
        {
            cin>>v;
            stack_1->clear();
            cout<<*stack_1;
            cout<<-1<<endl;
        }
        else if(ch==9)
        {
            cin>>v;
            stack_1->push(v);
            cout<<*stack_1;
            cout<<-1<<endl;
        }
        else if(ch==10)
        {
            cin>>v;
            temp=stack_1->pop();
            cout<<*stack_1;
            cout<<temp<<endl;
        }
        else if(ch==11)
        {
            cin>>v;
            cout<<*stack_1;
            cout<<stack_1->length()<<endl;
        }
        else if(ch==12)
        {
            cin>>v;
            cout<<*stack_1;
            cout<<stack_1->topValue()<<endl;
        }
        else
        {
            
        }

    }
}