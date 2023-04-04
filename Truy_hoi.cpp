#include <bits/stdc++.h>
using namespace std;

int A[101010];

void Init()
{
	A[0] = 5;
	A[1] = 9;
	A[2] = 12;
}

int calc(int n)
{
	if (n < 3)
		return A[n];
	for (int i = 3; i <= n; i++)
		A[i] = 8 * A[i - 1] - 21 * A[i - 2] + 19 * A[i - 3];
	return A[n];
}

int main()
{
	Init();
	int n;
	scanf("%d", &n);
	printf("%d\n", calc(n));
}