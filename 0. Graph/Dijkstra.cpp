#include <bits/stdc++.h>
#define MAX_INT 999999999
#define MAXN 10100
using namespace std;

int a[MAXN][MAXN], L[MAXN];
int n, m, s, e;

void init()
{
    cin >> n >> m >> s >> e;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[u][v] = a[v][u] = w;
    }
    for (int i = 1; i <= n; i++)
        L[i] = MAX_INT;
    L[s] = 0;
}

int P[MAXN];
bool path[MAXN];

void dijkstra()
{
    do
    {
        int u = e;
        for (int i = 1; i <= n; i++)
            if (!path[i] && L[u] > L[i])
                u = i;
        path[u] = true;
        if (L[u] == MAX_INT || u == e)
            break;

        for (int v = 1; v <= n; v++)
            if (a[u][v] > 0 && !path[v] && a[u][v] + L[u] < L[v])
            {
                L[v] = a[u][v] + L[u];
                P[v] = u;
            }
    } while (true);
}

void getPath(int s, int e)
{
    int u = e;
    vector<int> get;
    while (u != s)
    {
        get.push_back(u);
        u = P[u];
    }
    get.push_back(s);

    cout << "Path from " << s << " to " << e << ": ";
    for (int i = get.size() - 1; i >= 0; i--)
        if (i > 0)
            cout << get[i] << " --> ";
        else
            cout << get[i];
    cout << endl;
}

void print()
{
    if (L[e] == MAX_INT)
        cout << "Cannot move from " << s << " to " << e << endl;
    else
    {
        cout << "Min path from " << s << " to " << e << ": " << L[e] << endl;
        getPath(s, e);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    init();
    dijkstra();
    print();
    return 0;
}