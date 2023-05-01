#include"LRUCache.h"
int main()
{
    // freopen("lru_input->txt","r",stdin);
    // freopen("lru_output->txt","w",stdout);
    LRUCache<int, int, MyList<int>> *lru = new LRUCache<int, int, MyList<int>>(4);
    lru->put(1, 1);
    lru->put(2, 2);
    lru->put(3, 3);
    lru->put(4, 4);
    lru->show();
    cout << lru->get(2) << endl;
    lru->show();
    cout<<lru->get(2)<<endl;
    lru->show();
    cout << lru->get(5) << endl;
    lru->show();
    lru->put(3, 5);
    lru->show();
    lru->put(5, 69);
    lru->show();
    cout << "Second LRU\n";

    LRUCache<char *,int> *lru2=new LRUCache<char *,int>(2);
    lru2->put("Somik",1);
    lru2->put("Asif",2);
    lru2->put("Anup",3);
    lru2->show();
    cout<<lru2->get("Somik")<<endl;
    cout<<lru2->get("Asif")<<endl;
    lru2->show();
    lru2->put("Kabab",4);
    lru2->show();
    cout<<lru2->get("Anup")<<endl;
    cout<<"Third LRU\n";
    LRUCache<char *,string> *lru3=new LRUCache<char *,string>(4);
    // lru3->put("Somik","Dasgupta");
    // lru3->put("Asif","Karim");
    // lru3->put("Anup","Halder");
    // lru3->show();
    // lru3->put("Somik","Bhattacharjee");
    // lru3->show();
    // cout<<lru3->get("Asif");
    // lru3->show();
    // cout<<lru3->get("Kabab");
    // lru3->show();
    // lru3->put("Kabab","Mosha");
    // lru3->show();
    delete lru;
    delete lru2;
    delete lru3;
    /*
   int c, q, a, b;
   cin>>c;
   LRUCache<int,int> lruCache(c);
   cin>>q;
   while(q--)
   {
        cin>>a;
        if(a==2)
        {
            cin>>b>>c;
            lruCache.put(b,c);
        }
        else if(a==1)
        {
            cin>>b;
            cout<<lruCache.get(b)<<endl;
        }
   }*/
}