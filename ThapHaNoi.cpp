#include <stdio.h>
using namespace std;

int d = 0;

void move(char a, char c)
{
    printf("%c --> %c\n", a, c);
    ++d;
}

void Hanoi(int n, char a, char b, char c)
{
    if (n == 1)
        move(a, c);
    else
    {
        Hanoi(n - 1, a, c, b);
        Hanoi(1, a, b, c);
        Hanoi(n - 1, b, a, c);
    }
    return;
}

int n;

int main()
{
    scanf("%d", &n);
    char a = 'A', b = 'B', c = 'C';
    Hanoi(n, a, b, c);
    printf("%d", d);
    return 0;
}