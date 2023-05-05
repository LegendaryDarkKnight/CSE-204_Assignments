#include "Heap.h"
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int a, b;
    Heap h;
    string s;
    while (!feof(stdin))
    {
        cin>>s;
        if(s == "INS")
        {
            cin>>a;
            h.insert(a);
        }
        else if(s == "PRI")
        {
            h.Print();
        }
        else if(s == "DEC")
        {
            cin>>a>>b;
            h.DecreaseKey(a,b);
        }
        else if(s == "EXT")
        {
            cout<<"ExtractMin returned "<<h.extractMin()<<endl;
        }
        else if(s == "FIN")
        {
            cout<<"FindMin returned "<<h.FindMin()<<endl;
        }
    }
}
