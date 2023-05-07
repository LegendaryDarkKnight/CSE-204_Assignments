#include<bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define infinity 2147483647
#define NILL -1
class Vertices
{
public:
    int color;
    int d, f;
    int parent;
    Vertices()
    {
        color = WHITE;
        d = infinity;
        parent = NILL;
        f = infinity;
    }
};
void bfs(Vertices *&v,unordered_map<int,int> ladders,unordered_map<int,int> snakes, int x, int n)
{
    int start = 1, next;
    v[1].color = GRAY;
    v[1].d = 0;
    v[1].parent = NILL;
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        start = q.front();
        q.pop();
        if(start >= x)
        {
            continue;
        }
        if(ladders[start]!=0 )
        {
            if(v[ladders[start]].color == WHITE)
            {
                v[ladders[start]].color = GRAY;
                v[ladders[start]].d = v[start].d;
                v[ladders[start]].parent = start;
                q.push(ladders[start]);
            }
            v[start].color = BLACK;
            continue;
        }
        else if(snakes[start]!=0 )
        {
            if(v[snakes[start]].color == WHITE)
            {
                v[snakes[start]].color = GRAY;
                v[snakes[start]].d = v[start].d;
                v[snakes[start]].parent = start;
                q.push(snakes[start]);
            }
            v[start].color = BLACK;
            continue;
        }
        for(int i=1; i<=n; i++)
        {
            if(start+i>x)
                break;
            if(v[start+i].color == WHITE)
            {
                v[start+i].color = GRAY;
                v[start+i].d = v[start].d+1;
                v[start+i].parent = start;
                q.push(start+i);
            }
        }
        v[start].color = BLACK;
    }
}
void path(int x, Vertices *&v)
{
    if(x==1)
    {
        cout<<1<<endl;
        return;
    }
    cout<<x<<" ";
    path(v[x].parent,v);
}
void solve()
{
    int n, x, l, s, a, b;
    cin>>n>>x;
    unordered_map<int,int> ladders, snakes;
    vector<int> un;
    Vertices *v = new Vertices[x+1];
    cin>>l;
    for(int i=0; i<l; i++)
    {
        cin>>a>>b;
        ladders[a] = b;
    }
    cin>>s;
    for (int i = 0; i <s; i++)
    {
        cin>>a>>b;
        snakes[a] = b;
    }
    bfs(v,ladders,snakes, x, n);

    
    if(v[x].d!=infinity){
        cout<<v[x].d<<endl;
        path(x,v);
        cout<<"All reacheable\n";
        return ;
    }
    cout<<-1<<endl;
    cout<<"No Solutions\n";
    for(int i=1; i<=x; i++)
    {
        if(v[i].d==infinity)
            cout<<i<<" ";
    }
    cout<<"\n";
}
int main()
{
    freopen("snake_in.txt","r",stdin);
    freopen("snake_out.txt","w",stdout);
    int t;
    cin>>t;
    while(t--)
        solve();
}