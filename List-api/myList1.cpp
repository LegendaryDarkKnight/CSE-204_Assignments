#include "MyList_LL.h"
#include "MyList_Arr.h"

template <class var>
void menu(MyList<var> *&L)
{
    int choice, x, d;
    var item;
    cin >> choice;
    if (choice == 1)
    {
        cin >> item;
        cout << *L;
        cout << L->size() << endl;
    }
    else if (choice == 2)
    {
        cin >> item;
        L->push(item);
        cout << *L;
        cout << -1 << endl;
    }
    else if (choice == 3)
    {
        cin >> item;
        L->pushBack(item);
        cout << *L;
        cout << -1 << endl;
    }
    else if (choice == 4)
    {
        cin >> item;
        x = L->erase();
        cout << *L;
        cout << x << endl;
    }
    else if (choice == 5)
    {
        cin >> item;
        L->setToBegin();
        cout << *L;
        cout << -1 << endl;
    }
    else if (choice == 6)
    {
        cin >> item;
        L->setToEnd();
        cout << *L;
        cout << -1 << endl;
    }
    else if (choice == 7)
    {
        cin >> item;
        L->prev();
        cout << *L;
        cout << -1 << endl;
    }
    else if (choice == 8)
    {
        cin >> item;
        L->next();
        cout << *L;
        cout << -1 << endl;
    }
    else if (choice == 9)
    {
        cin >> item;
        x = L->currPos();
        cout << *L;
        cout << x << endl;
    }
    else if (choice == 10)
    {
        cin >> item;
        L->setToPos(item);
        cout << *L;
        cout << -1 << endl;
    }
    else if (choice == 11)
    {
        cin >> item;
        var y = L->getValue();
        cout << *L;
        cout << y << endl;
    }
    else if (choice == 12)
    {
        cin >> item;
        x = L->find(item);
        cout << *L;
        cout << x << endl;
    }
    else if (choice == 13)
    {
        cin >> item;
        L->clear();
        cout << *L;
        cout << -1 << endl;
    }
    else
    {
        cin >> item;
    }
}
int main()
{
    MyList<int> *list;
    int k, x, a, q;
    freopen("list_input.txt", "r", stdin);
    freopen("list_output.txt", "w", stdout);
    cin >> k >> x;
    list = new LL<int>(x);
    while (k--)
    {
        cin >> a;
        list->pushBack(a);
    }
    cout << *list;
    cin >> q;
    while (q--)
        menu(list);
}
