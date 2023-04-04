#include <bits/stdc++.h>
#define MAXN 101
#define INF 999999
using namespace std;

void print(int a[][MAXN], int n)
{
    cout << "Result:";
    for (int i = 1; i <= n; i++)
    {
        cout << endl
             << "       ";
        for (int j = 1; j <= n; j++)
            if (a[i][j] == INF)
                cout << "INF ";
            else
                cout << a[i][j] << " ";
    }
}

void FloydWarshall(int a[][MAXN], int n)
{
    int path[MAXN][MAXN];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            path[i][j] = a[i][j];
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (path[i][j] > path[i][k] + path[k][j] && path[k][j] != INF && path[i][k] != INF)
                    path[i][j] = path[i][k] + path[k][j];
    print(path, n);
}

int a[MAXN][MAXN];
int n, m;

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = INF;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[u][v] = w;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    init();
    FloydWarshall(a, n);
    return 0;
}