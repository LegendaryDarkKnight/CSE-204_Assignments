#include "MyList_LL.h"
#include "MyList_Arr.h"
#include<cstring>

template <class var1, class var2, class X = MyList<var1>>
class LRUCache
{
    int capacity, total;
    var1 k;
    var2 v;

    MyList<var2> *values;
    MyList<var1> *keys;

public:
    LRUCache(int c)
    {
        total = 0;
        capacity = c;

        values = new LL<var2>(c);
        keys = new LL<var1>(c);
    }
    ~LRUCache()
    {
        values->clear();
        keys->clear();
        delete values;
        delete keys;
    }
    var2 get(var1 key)
    {
        var2 ans;
        int x = keys->find(key);
        if (x == -1)
        {
            return -1;
        }
        else if(x==keys->size()-1)
        {
            values->setToEnd();
            ans=values->getValue();
            values->setToBegin();
        }
        else
        {
            values->setToPos(x);
            keys->setToPos(x);
            k = keys->getValue();
            ans = v = values->getValue();
            values->erase();
            keys->erase();
            values->pushBack(v);
            keys->pushBack(k);
            values->setToBegin();
            keys->setToBegin();
        }
        return ans;
    }
    void put(var1 key, var2 value)
    {
        int x = keys->find(key);
        if (total < capacity)
        {
            if (x != -1)
            {
                values->setToPos(x);
                keys->setToPos(x);
                k = keys->getValue();
                values->erase();
                keys->erase();
                values->pushBack(value);
                keys->pushBack(k);
                values->setToBegin();
                keys->setToBegin();
                return;
            }
            keys->pushBack(key);
            values->pushBack(value);
            total++;
        }
        else
        {
            if (x != -1)
            {
                values->setToPos(x);
                keys->setToPos(x);
                k = keys->getValue();
                values->erase();
                keys->erase();
                values->pushBack(value);
                keys->pushBack(k);
                values->setToBegin();
                keys->setToBegin();
                return;
            }
            keys->erase();
            values->erase();
            keys->pushBack(key);
            values->pushBack(value);
        }
    }
    void show()
    {
        cout << *keys;
        cout << *values;
    }
};
