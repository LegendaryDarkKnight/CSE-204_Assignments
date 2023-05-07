#include "QueueArrLL.hpp"
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
class Pair
{
public:
    int x;
    int y;
    Pair(int u = 0, int v = 0)
    {
        x = u, y = v;
    }
    friend ostream &operator<<(ostream &out, Pair *p);
};
ostream &operator<<(ostream &out, Pair *p)
{
    out << "(" << p->x << "," << p->y << ")";
    return out;
}
void bfs(Arr<int> *&list, Vertices *&v, int s, int n, Arr<Pair *> &bfs_l, Arr<int> &bfs_v)
{
    if (s > n and s<0)
    {
        cout << "Invalid";
        return;
    }
    int u, x, i = 0;
    v[s].color = GRAY;
    v[s].d = 0;
    QueueLL<int> q;
    q.enqueue(s);
    while (q.length())
    {
        u = q.dequeue();
        i = 0;
        while (i < list[u].size())
        {
            x = list[u].getValue();
            if (v[x].color == WHITE)
            {
                v[x].color = GRAY;
                v[x].d = v[u].d + 1;
                bfs_l.pushBack(new Pair(u , x ));
                v[x].parent = u;
                q.enqueue(x);
            }
            i++;
            list[u].next();
        }
        v[u].color = BLACK;
        bfs_v.pushBack(u );
    }
}
void dfs(Arr<int> *&list, Vertices *&v, int &time, int n, int s, Arr<Pair *> &dfs_l, Arr<int> &dfs_v)
{
    v[s].d = ++time;
    v[s].color = GRAY;
    int i = 0, x;
    while (i < list[s].size())
    {
        x = list[s].getValue();
        if (v[x].color == WHITE)
        {
            v[x].parent = s;
            dfs_l.pushBack(new Pair(s , x ));
            dfs(list, v, time, n, x, dfs_l, dfs_v);
        }

        list[s].next();
        i++;
    }
    dfs_v.pushBack(s);

    v[s].color = BLACK;
    v[s].f = ++time;
    return;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, m, x, y, s;
    cin >> n >> m;
    Arr<Pair *> bfs_l;
    Arr<int> bfs_v;
    LL<int> sp;
    Arr<Pair *> dfs_l;
    Arr<int> dfs_v;
    Arr<int> *list = new Arr<int>[n+1];
    Arr<int> *bfst = new Arr<int>[n+1];
    Arr<int> *dfst = new Arr<int>[n+1];
    Vertices *v = new Vertices[n+1];
    Vertices *v1 = new Vertices[n+1];
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        list[x].pushBack(y);
    }
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        list[i].setToBegin();
    }

    bfs(list, v, s , n, bfs_l, bfs_v);
    for(int i=0; i<bfs_l.size(); i++)
    {
        bfst[bfs_l.getValue()->x].pushBack(bfs_l.getValue()->y);
        bfs_l.next();
    }
    cout<<"BFS Tree\n";
    for(int i=0; i<n; i++)
    {
        if(bfst[i].size())
        {
        cout<<i<<"->";
        cout<<bfst[i];
        }
    }
    
    cout<<bfs_v;
    cout<<bfs_l;
    for (int i = 0; i <= n; i++)
    {
        if (i == s)
        {
            cout<<i<<" is the source\n";
            continue;
        }
        x = bfs_v.find(i);
        if(x == -1)
        {
            cout<<i<<" is not accessible\n";
            continue;
        }
        y = i;
        while(y!=s)
        {
            sp.push(y);
            y = v[y].parent;
        }

        sp.push(s);
        cout<<i<<" "<<sp;
        sp.clear();
    }

    for (int i = 0; i < n; i++)
    {
        list[i].setToBegin();
    }
    int time = 0;
    //dfs_v.pushBack(s);
    dfs(list, v1, time, n, s , dfs_l, dfs_v);
    //cout << "After dfs\n";
    //cout << time << endl;
    cout << dfs_v;
    cout << dfs_l;
    for(int i=0; i<dfs_l.size(); i++)
    {
        dfst[dfs_l.getValue()->x].pushBack(dfs_l.getValue()->y);
        dfs_l.next();
    }
    cout<<"DFS Tree\n";
    for(int i=0; i<n; i++)
    {
        if(dfst[i].size())
        {
        cout<<i<<"->";
        cout<<dfst[i];
        }
    }

    delete[] list;
    delete[] v;
}