#ifndef ARRHeader
#define ARRHeader
//#include <iostream>
#include "MyList.h"
//using namespace std;
template <class var>
class Arr : public MyList<var>
{
    var *arr;
    int curr_pos, total, max_size;

public:
    Arr()
    {
        total = 0;
        curr_pos = 0;
        max_size = 1;
        //arr = (var *)calloc(max_size, sizeof(var));
        arr=new var[max_size];
    }
    Arr(int size)
    {
        arr=new var[size];
        total = 0;
        curr_pos = 0;
        max_size = size;
    }
    Arr(const Arr<var> &l)//Time Complexity: O(total)
    {
        //cout << "IN copy\n";
        total = l.total;
        curr_pos = l.curr_pos;
        max_size = l.max_size;
        arr=new var[max_size];
        for (int i = 0; i < total; i++)
            arr[i] = l.arr[i];
    }
    Arr(var array[], int total)//Time Complexity: O(total)
    {
        this->total=total;
        max_size=sizeof(array)/sizeof(array[0]);
        arr=new var[max_size];
        for (int i = 0; i < total; i++)
            arr[i] = array[i];
        curr_pos=total/2;
    }
    ~Arr()
    {
        delete[] arr;
    }
    int size()//Time Complexity: O(1)
    {
        return total;
    }
    void push(var item)//Time Complexity: O(total)
    {
        try
        {
            if (total == max_size)
                throw 2 * max_size;
        }
        catch (int n)
        {
            max_size = 2 * max_size;
            var *temp=new var[n];
            for(int i=0; i<total; i++)
            temp[i]=arr[i];
           //arr = (var *)realloc(arr, n * sizeof(var)); 
           delete []arr;
           arr=new var[n];
           for(int i=0; i<total; i++)
            arr[i]=temp[i];
           delete []temp; 
        }
        for (int i = total - 1; i >= curr_pos; i--)
        {
            arr[i + 1] = arr[i];
        }
        total++;
        arr[curr_pos] = item;
    }
    void pushBack(var item)//Time Complexity: O(max_size) => in case of dynamically increasing space else O(1) 
    {
        try
        {
            if (total == max_size)
                throw 2 * max_size;
        }
        catch (int n)
        {
             max_size = 2 * max_size;
            var *temp=new var[n];
            for(int i=0; i<total; i++)
            temp[i]=arr[i];
           //arr = (var *)realloc(arr, n * sizeof(var)); 
           delete []arr;
           arr=new var[n];
           for(int i=0; i<total; i++)
            arr[i]=temp[i];
           delete []temp;
        }
        //cout<<item<<endl;
        arr[total++] = item;
        //cout<<2;
    }
    
    var erase()//Time Complexity: O(total)
    {
        var x = arr[curr_pos];
        for (int i = curr_pos; i < total-1; i++)
        {
            arr[i] = arr[i + 1];
        }
        if(curr_pos==total-1&&curr_pos>=1)
        {
            curr_pos--;
        }
        total--;
        try
        {
            if (total <= max_size/2 && max_size>=2)
                throw max_size / 2;
        }
        catch (int n)
        {
            max_size /= 2 ;
            var *temp=new var[max_size];
            for(int i=0; i<total; i++)
            temp[i]=arr[i];
           //arr = (var *)realloc(arr, n * sizeof(var)); 
           delete[] arr;
           arr=new var[max_size];
           for(int i=0; i<total; i++)
            arr[i]=temp[i];
           delete[] temp;
        }
        return x;
    }
    void setToBegin()//Time Complexity: O(1)
    {
        curr_pos = 0;
    }
    void setToEnd()//Time Complexity: O(1)
    {
        curr_pos = total - 1;
    }
    void prev()//Time Complexity: O(1)
    {
        if (curr_pos == 0)
            return;
        else
            curr_pos--;
    }
    void next()//Time Complexity: O(1)
    {
        if (curr_pos == total - 1)
        {
            return;
        }
        curr_pos++;
    }
    int currPos()//Time Complexity: O(1)
    {
        return curr_pos;
    }
    void setToPos(int pos)//Time Complexity: O(total)
    {
        try
        {
            if (pos < 0 && pos >= total)
                throw 1;
        }
        catch (int n)
        {
            if (n == 1)
                //cout << "Wrong indexing" << endl;
            return;
        }
        curr_pos = pos;
    }
    
    var getValue()//Time Complexity: O(1)
    {
        return arr[curr_pos];
    }
    int find(var item)//Time Complexity: O(total)
    {
        for (int i = 0; i < total; i++)
        {
            if (arr[i] == item)
                return i;
        }
        return -1;
    }
    void clear()//Time Complexity: O(1)
    {
        total = 0;
        curr_pos = 0;
        max_size = 1;
        delete[]arr;
        arr=new var[max_size];
    }
    void show()//Time Complexity: O(total). This function is written only for test purpose
    {
        cout << "\n<";
        for (int i = 0; i < total; i++)
        {
            if (i == curr_pos)
                cout << "|";
            cout << arr[i] << ", ";
        }
        cout << ">\n";
    }
    int maxSize(){return max_size;}//only for test purpose
    var *getArray()//only for test purpose
    {
        return arr;
    }
};
#endif