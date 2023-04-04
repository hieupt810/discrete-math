#include <stdio.h>

int n, k;
int x[1010];

void Print()
{
	for (int i = 0; i < n; i++)
		printf("%d ", x[i]);
	printf("\n");
}

void Try(int i, int sum)
{
	if (i == n)
	{
		if (sum == k)
			Print();
		return;
	}
	for (int j = 0; j <= k; j++)
	{
		x[i] = j;
		Try(i + 1, sum + j);
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	Try(0, 0);
}