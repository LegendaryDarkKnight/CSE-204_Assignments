#include <bits/stdc++.h>
using namespace std;
int merging(int arr[], int s, int mid, int e, vector<pair<int,int>> &v)
{
    int n1= mid - s+1;
    int n2= e - mid;
    int count = 0;
    int a[n1];
    int b[n2];
    for(int i=0; i<n1; i++)
        a[i] = arr[s+i];
    for(int i=0; i<n2; i++)
        b[i] = arr[mid+1+i];
    int i=0, j=0, k = s, li=0;
    while(i<n1 and j<n2)
    {
        if(a[i]<=b[j])
        {
            arr[k] = a[i];
            k++; i++;
        }
        else
        {
            count+=n1-i;
            //for(int m = i; m<n1; m++)
            //    v.push_back(make_pair(a[m],b[j]));
            li = i;
            arr[k] = b[j];
            k++; j++;
        }
    }
    while(i<n1)
    {
        arr[k] = a[i];
        k++; i++;
    }
    while(j<n2)
    {
        arr[k] = b[j];
        k++; j++;
    }
    return count;

}
int inversions(int a[], int s, int e, vector<pair<int,int>> &v)
{
    if(s==e)
        return 0;
    int mid = (s+e)/2;
    int s1 = inversions(a,s,mid,v);
    int s2 = inversions(a,mid+1,e,v);
    int s3 = merging(a,s,mid,e,v);
    return s1+s2+s3;

}
void countpairs(int a[], int n, vector<pair<int,int>> &v)
{
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(a[j]<a[i])
                v.push_back(make_pair(a[i],a[j]));

}
int main()
{
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    vector<pair<int,int>> v;
    countpairs(a,n,v);

    cout<<inversions(a,0, n-1, v)<<endl;
    cout<<"Inverted Pairs: ";
    for(int i=0; i<v.size(); i++)
        cout<<"("<<v[i].first<<","<<v[i].second<<")"<<((i+1!=v.size())?", ":"");
}
