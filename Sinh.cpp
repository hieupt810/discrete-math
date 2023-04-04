#include <bits/stdc++.h>
using namespace std;

int n, k;

bool isLast(int x[])
{
	if (x[0] != k)
		return false;
	for (int i = 1; i < n; i++)
		if (x[i] != 0)
			return false;
	return true;
}

void Print(int x[])
{
	for (int i = 0; i < n; i++)
		printf("%d ", x[i]);
	printf("\n");
}

void ToNext(int x[])
{
	int sum = k;
	int i = 0;
	while (sum > 0)
	{
		sum -= x[i];
		i++;
	}
	i -= 2;
	x[i]++;
	sum = k;
	for (int j = 0; j <= i; j++)
		sum -= x[j];
	for (int j = i + 1; j < n; j++)
		x[j] = 0;
	x[n - 1] = sum;
}

void Generate(int n, int k)
{
	int x[n];
	for (int i = 0; i < n - 1; i++)
		x[i] = 0;
	x[n - 1] = k;
	Print(x);
	while (!isLast(x))
	{
		ToNext(x);
		Print(x);
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	Generate(n, k);
}