#include <bits/stdc++.h>
using namespace std;
class Interval
{
public:
    int start;
    int end;
};
bool compare(Interval i1, Interval i2)
{
    if (i1.end < i2.end) return true;
    else if (i1.end == i2.end)
    {
        return (i1.start<=i2.start);
        /* code */
    }
    else
        return false;

    //return ((i1.end < i2.end) ? true : (i1.start <= i2.start));
}
void swap(Interval &i1, Interval &i2)
{
    Interval temp = i1;
    i1 = i2;
    i2 = temp;
}
void Heapify(Interval a[], int n)
{
    int j;
    Interval temp;
    for(int i=n-1; i>=n/2; i--)
    {
        j=i;
        while ( j>0)
        {
            //if(a[(j-1)/2].end > a[j].end)
            if(compare(a[j],a[(j-1)/2]))
            {
                swap(a[(j-1)/2],a[j]);
            }
            j = (j-1)/2;
        }
    }
}
int main()
{
    //time_t start, end1;
    //time(&start);
    ios_base::sync_with_stdio(false);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, c=1, end;
    cin >> n;
    Interval b[n], ans[n], a[n];
    for (int i = 0; i < n; i++)
        cin >> b[i].start >> b[i].end;
    // for(int i = 0; i<n; i++)
    //     cout<<b[i].start<<" "<<b[i].end<<endl;
    Heapify(b,n);
    int m=n;
    for(int i=0; i<n; i++)
    {
        a[i]= b[0];
        b[0]= b[--m];
        Heapify(b,m);
    }
    // for(int i = 0; i<n; i++)
    //     cout<<a[i].start<<" "<<a[i].end<<endl;
    // sort(b,b+n,compare);



    ans[0] = a[0];
    end = ans[0].end;
    for (int i=1; i<n; i++)
    {
        if(a[i].start>=end)
        {
            end = a[i].end;
            ans[c++] = a[i];
        }
    }
    cout<<c<<endl;
    for(int i=0; i<c; i++)
        cout<<ans[i].start<<" "<<ans[i].end<<endl;
    //time(&end1);

   /* double time_taken = double(end1 - start);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(10);
    cout << " sec " << endl;*/
}
