#include <bits/stdc++.h>
#define MAXN 10100
using namespace std;

struct Tree
{
    int u, v;
    int w;
};

void quickSort(Tree a[], int left, int right)
{
    int i = left, j = right;
    int pivot = a[(left + right) / 2].w;
    while (i <= j)
    {
        while (a[i].w < pivot)
            i++;
        while (a[j].w > pivot)
            j--;
        if (i <= j)
        {
            swap(a[i].w, a[j].w);
            swap(a[i].u, a[j].u);
            swap(a[i].v, a[j].v);
            ++i;
            --j;
        }
    }
    if (left < j)
        quickSort(a, left, j);
    if (i < right)
        quickSort(a, i, right);
}

int n, m;
int root[MAXN], _rank[MAXN];
struct Tree Path[MAXN];

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Path[i].u = u;
        Path[i].v = v;
        Path[i].w = w;
    }
    for (int i = 1; i <= m; i++)
    {
        root[i] = i;
        _rank[i] = 0;
    }
}

int find(int u)
{
    if (root[u] != u)
        return find(root[u]);
    return root[u];
}

void merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return;
    if (_rank[u] < _rank[v])
        root[u] = v;
    else if (_rank[u] > _rank[v])
        root[v] = u;
    else
    {
        _rank[u]++;
        root[v] = u;
    }
}

bool repeat_cycle(int u, int v)
{
    return (find(u) == find(v));
}

void Kruskal()
{
    vector<int> t;
    for (int i = 0; i < m && t.size() < n - 1; i++)
        if (!repeat_cycle(Path[i].u, Path[i].v))
        {
            merge(Path[i].u, Path[i].v);
            t.push_back(i);
        }
    if (t.size() < n - 1)
        cout << "Cannot find" << endl;
    else
    {
        cout << "Result:" << endl;
        for (int i = 0; i < t.size(); i++)
            cout << "        " << Path[t[i]].u << " " << Path[t[i]].v << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    init();
    quickSort(Path, 1, m);
    // for (int i = 1; i <= m; i++) cout << "  " << Path[i].w << " (" << Path[i].u << ", " << Path[i].v << ")" << endl;
    Kruskal();
    return 0;
}