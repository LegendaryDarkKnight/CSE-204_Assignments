#include <bits/stdc++.h>
using namespace std;
class Pair
{
    int x, y;
};
int main()
{
    vector<pair<int,int>> v;
    int n, a, b;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a>>b;
        //pair<int,int> p(a,b);
        v.push_back(make_pair(b,a));
    }
    sort(v.begin(),v.end());
    for(int i=0; i<n; i++)
    {
        cout<<"Arrival "<<v[i].second<<" Dept: "<<v[i].first<<endl;
    }
    
}