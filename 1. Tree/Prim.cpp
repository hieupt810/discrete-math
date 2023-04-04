#include <bits/stdc++.h>
#define INF 999999;
#define MAXN 101
using namespace std;

int getMin(int a[], bool prim[], int n)
{
    int min = INT_MAX, id;
    for (int i = 1; i <= n; i++)
        if (!prim[i] && a[i] < min)
        {
            min = a[i];
            id = i;
        }
    return id;
}

void print(int root[], int a[][MAXN], int n)
{
    cout << "Result:" << endl;
    for (int i = 2; i <= n; i++)
        cout << "      " << root[i] << " " << i << "  " << a[i][root[i]] << endl;
}

void getPrim(int a[][MAXN], int n)
{
    int root[MAXN], minEdge[MAXN];
    bool prim[MAXN];
    for (int i = 0; i <= n; i++)
    {
        minEdge[i] = INF;
        prim[i] = false;
    }
    minEdge[0] = minEdge[1] = 0;
    root[0] = root[1] = -1;
    for (int i = 1; i <= n - 1; i++)
    {
        int u = getMin(minEdge, prim, n);
        prim[u] = true;
        for (int j = 1; j <= n; j++)
            if (a[i][j] && !prim[j] && a[i][j] < minEdge[j])
            {
                root[j] = i;
                minEdge[j] = a[i][j];
            }
    }
    print(root, a, n);
}

int a[MAXN][MAXN];
int n, m;

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[u][v] = a[v][u] = w;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    init();
    getPrim(a, n);
    return 0;
}