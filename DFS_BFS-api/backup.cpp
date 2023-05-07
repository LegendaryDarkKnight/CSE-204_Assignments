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
    if (s >= n)
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
                bfs_l.pushBack(new Pair(u + 1, x + 1));
                v[x].parent = u;
                q.enqueue(x);
            }
            i++;
            list[u].next();
        }
        v[u].color = BLACK;
        bfs_v.pushBack(u + 1);
    }
}
void dfs(Arr<int> *&list, Vertices *&v, int &time, int n, int s, Arr<Pair *> &dfs_l, Arr<int> &dfs_v)
{
    dfs_v.pushBack(s + 1);
    v[s].d = ++time;
    v[s].color = GRAY;
    int i = 0, x;
    while (i < list[s].size())
    {
        x = list[s].getValue();
        if (v[x].color == WHITE)
        {
            v[x].parent = s;
            dfs_l.pushBack(new Pair(s + 1, x + 1));
            dfs(list, v, time, n, x, dfs_l, dfs_v);
        }
        list[s].next();
        i++;
    }
    v[s].color = BLACK;
    v[s].f = ++time;
    return;
}
int main()
{
    freopen("s1_in.txt", "r", stdin);
    freopen("s1_out.txt", "w", stdout);
    int n, m, x, y, s;
    cin >> n >> m;
    Arr<Pair *> bfs_l;
    Arr<int> bfs_v;
    LL<int> sp;
    Arr<Pair *> dfs_l;
    Arr<int> dfs_v;
    Arr<int> *list = new Arr<int>[n];
    Vertices *v = new Vertices[n];
    Vertices *v1 = new Vertices[n];
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        list[x - 1].pushBack(y - 1);
    }
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        list[i].setToBegin();
    }

    bfs(list, v, s - 1, n, bfs_l, bfs_v);
    cout << "after bfs\n";
    cout << bfs_v;
    cout << bfs_l;
    
    // for (int i = 1; i <= n; i++)
    // {
    //     if (i == s)
    //     {
    //         cout<<i<<" is the source\n";
    //         continue;
    //     }
    //     x = bfs_v.find(i);
    //     if(x == -1)
    //     {
    //         cout<<i<<" is not accessible\n";
    //         continue;
    //     }
    //     y = i-1;
    //     while(y!=s-1)
    //     {

    //     }
    // }

    for (int i = 0; i < n; i++)
    {
        list[i].setToBegin();
    }
    int time = 0;
    dfs(list, v1, time, n, s - 1, dfs_l, dfs_v);
    cout << "After dfs\n";
    cout << time << endl;
    cout << dfs_v;
    cout << dfs_l;

    delete[] list;
    delete[] v;
}