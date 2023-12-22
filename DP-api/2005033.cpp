#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int w[n+1], v[n+1], weight;
    for(int i=1; i<=n; i++)
        cin>>w[i]>>v[i];
    cin>>weight;
    int sack[n+1][weight+1]={0};
    for(int i=0; i<=weight; i++)
        sack[0][i] = 0;
    for(int i=0; i<=n; i++)
        sack[i][0] = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=weight; j++)
        {
            if(w[i]>j)
            {
                sack[i][j]=sack[i-1][j];
            }
            else
            {
                if(v[i]+sack[i-1][j-w[i]]>sack[i-1][j])
                    sack[i][j] = v[i]+sack[i-1][j-w[i]];
                else
                    sack[i][j] = sack[i-1][j];

            }
        }
    }
    cout<<sack[n][weight];
    stack<int> s;
    cout<<"\nWeights: ";
    int i=n, j=weight;
    while(i>0)
    {
        if(sack[i-1][j]!=sack[i][j])
        {
            s.push(w[i]);
            j-=w[i];
        }
        i--;
    } 
    while(!s.empty()){
        cout<<s.top()<<" "; s.pop();}
}