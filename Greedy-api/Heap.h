#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Heap
{
    int *a;
    int max_size;
    int top;

public:
    Heap()
    {
        max_size = 1;
        a = (int *)calloc(max_size, sizeof(int));
        memset(a, -1, max_size * sizeof(int));
        top = 0;
    }
    Heap(int maxsize)
    {
        max_size = maxsize;
        a = (int *)calloc(max_size, sizeof(int));
        memset(a, -1, max_size * sizeof(int));
        top = 0;
    }
    Heap(const Heap &h)
    {
        max_size = h.max_size;
        top = h.top;
        a = (int *)calloc(max_size, sizeof(int));
        memset(a, -1, max_size * sizeof(int));
        for(int i = 0; i<top; i++)
            a[i] = h.a[i];
    }
    ~Heap()
    {
        free(a);
    }
    void insert(int item)
    {
        cout<<"INSERTED "<<item<<endl;
        if (top == 0)
        {
            a[top] = item;
            top++;
            return;
        }
        int x = top;
        a[top] = item;
        while (x > 0)
        {
            if (a[(x - 1) / 2] <= a[x])
            {
                break;
            }
            if (a[(x - 1) / 2] > a[x])
                swap(a[(x - 1) / 2], a[x]);
            x = (x - 1) / 2;
        }
        top++;
        if (top >= max_size)
        {
            max_size = max_size * 2 + 2;
            a = (int *)realloc(a, max_size * sizeof(int));
            for (int i = top; i < max_size; i++)
                a[i] = -1;
        }
        return;
    }
    int Delete(int i)
    {
        if (i >= top and i < 0)
            return -1;
        if (a[i] == -1)
        {
            cout << "Not available\n";
            return -1;
        }
        int temp = a[i];
        a[i] = a[top - 1];

        if (a[top - 1] > temp)
        {

            while (a[i] != -1)
            {
                if (2 * i + 1 >= top or 2 * i + 2 >= top)
                    break;
                if (a[2 * i + 1] == -1 and a[2 * i + 2] == -1)
                    break;
                if (a[2 * i + 1] == -1 and a[2 * i + 2] != -1)
                {
                    if (a[2 * i + 2] < a[i])
                        swap(a[2 * i + 2], a[i]);
                    else
                        break;
                    i = 2 * i + 2;
                }
                else if (a[2 * i + 1] != -1 and a[2 * i + 2] == -1)
                {
                    if (a[2 * i + 1] < a[i])
                        swap(a[2 * i + 1], a[i]);
                    else
                        break;
                    i = 2 * i + 1;
                }
                else
                {
                    if (a[2 * i + 2] < a[2 * i + 1])
                    {
                        if (a[2 * i + 2] < a[i])
                            swap(a[2 * i + 2], a[i]);
                        else
                            break;
                        i = 2 * i + 2;
                    }
                    else if (a[2 * i + 1] < a[2 * i + 2])
                    {
                        if (a[2 * i + 1] < a[i])
                            swap(a[2 * i + 1], a[i]);
                        else
                            break;
                        i = 2 * i + 1;
                    }
                    else
                        break;
                }
            }
        }
        else if (a[top - 1] < temp)
        {
            while (i > 0)
            {
                if (a[(i - 1) / 2] <= a[i])
                {
                    break;
                }
                if (a[(i - 1) / 2] > a[i])
                    swap(a[(i - 1) / 2], a[i]);
                i = (i - 1) / 2;
            }
        }
        a[--top] = -1;
        if (2 * top + 2 < max_size && max_size > 1)
        {
            max_size /= 2;
            a = (int *)realloc(a, max_size * sizeof(int));
        }
        return temp;
    }
    int extractMin()
    {
        return Delete(0);
    }
    void show()
    {
        for (int i = 0; i < top; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    void treeForm()
    {
        int diff = 2, prev = 0;
        for (int i = 0; i < top; i++)
        {
            cout << a[i] << " ";
            if (i == prev)
            {
                prev += diff;
                diff *= 2;
                cout << endl;
            }
        }
    }
    void clearAll()
    {
        free(a);
        top = 0;
        max_size = 1;
        a = (int *)calloc(max_size, sizeof(int));
    }
    bool isEmpty()
    {
        return top == 0;
    }
    void Print()
    {
        cout<<"Printing the binary heap ...\n";
        for(int i=1; i<= 20; i++)
            cout<<"- ";
        cout<<endl;
        int level = 0, i = 0, l = 0, r = 0;

        while(a[i]!=-1 and i<top)
        {
            if(i == l)
                cout<<"Level "<<level<<" : ";
            cout<<a[i]<<" ";
            if(i == r){
                if(r+1!=top)
                {
                    if(a[r+1]!=-1)
                        cout<<endl;
                }
                r=2*r+2;
                l=2*l+1;
                level++;

            }
            i++;
        }
        cout<<endl;
        for(int i=1; i<= 20; i++)
            cout<<"- ";
        cout<<endl;
    }
    void DecreaseKey(int prevKey, int newKey)
    {
        int k = -1;
        for(int i = 0; i<top; i++)
        {
            if(prevKey == a[i])
            {
                k = i;
                break;
            }
        }
        if(k == -1)
        {
            cout<<"Not Found\n";
            return;
        }
        if(a[k]<newKey)
        {
            cout<<"New key must be lower than prevkey\n";
            return;
        }
        a[k] = newKey;
        while(k>0)
        {
            if(a[(k-1)/2] > a[k])
            {
                swap(a[(k-1)/2] , a[k]);
                k=(k-1)/2;
            }
            else
                break;
        }
        cout<<prevKey<<" decreased to "<<newKey<<endl;

    }
    int FindMin()
    {
        return a[0];
    }
};