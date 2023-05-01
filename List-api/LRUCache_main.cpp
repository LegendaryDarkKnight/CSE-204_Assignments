#include"LRUCache.h"
int main()
{
    freopen("lru_input.txt","r",stdin);
    freopen("lru_output.txt","w",stdout);
    int c, q, a, b;
   cin>>c;
   LRUCache<int,int> *lruCache=new LRUCache<int,int>(c);
   cin>>q;
   while(q--)
   {
        cin>>a;
        if(a==2)
        {
            cin>>b>>c;
            lruCache->put(b,c);
        }
        else if(a==1)
        {
            cin>>b;
            cout<<lruCache->get(b)<<endl;
        }
   }
}