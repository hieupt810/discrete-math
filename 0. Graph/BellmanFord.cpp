#include <bits/stdc++.h>
using namespace std;

const int maxC = 10000;

int n, S, F, c[101][101], d[101], Trace[101];

void loadGraph()
{
    int m;
    cin >> n >> m >> S >> F;
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
        {
            if (u == v)
                c[u][v] = 0;
            else
                c[u][v] = maxC;
        }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v >> c[u][v];
    }
    return;
}

void init()
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = c[S][i];
        Trace[i] = S;
    }
    return;
}

void Ford_Bellman()
{
    int countLoop = 0;
    bool Stop;
    do
    {
        Stop = true;
        for (int u = 1; u <= n; u++)
            for (int v = 1; v <= n; v++)
            {
                if (d[v] > d[u] + c[u][v])
                {
                    d[v] = d[u] + c[u][v];
                    Trace[v] = u;
                    Stop = false;
                }
            }
        // cout << countLoop + 2 << " --> ";
        // for (int i = 1; i <= n; i++) cout << d[i] << "  ";
        ++countLoop;
        cout << endl;
    } while (!(Stop == true || countLoop >= n - 2));
    return;
}

void print()
{
    if (d[F] == maxC)
        cout << "Path from " << S << " to " << F << " not found" << endl;
    else
    {
        cout << "Distance from " << S << " to " << F << ": " << d[F] << endl
             << "Path: ";
        while (F != S)
        {
            cout << F << " <- ";
            F = Trace[F];
        }
        cout << S << endl;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    loadGraph();
    init();
    Ford_Bellman();
    print();
    return 0;
}