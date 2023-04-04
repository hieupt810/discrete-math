#include <bits/stdc++.h>
using namespace std;

bool isCalc[100100];
int A[100100];

void Init()
{
	A[0] = 5;
	A[1] = 9;
	A[2] = 12;
	isCalc[0] = isCalc[1] = isCalc[2] = true;
}

int calc(int n)
{
	if (n < 0)
		return 0;
	if (isCalc[n])
		return A[n];
	isCalc[n] = true;
	return A[n] = 8 * calc(n - 1) - 21 * calc(n - 2) + 19 * calc(n - 3);
}

int main()
{
	Init();
	int n;
	scanf("%d", &n);
	printf("%d", calc(n));
}