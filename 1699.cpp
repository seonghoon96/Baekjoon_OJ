#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 100000 + 1
#define mod 1000000000
#define ll long long

int n;
int sqr[MAX];
void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        sqr[i] = i;
}

void solution()
{
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j * j <= i; j++)
        {
            sqr[i] = min(sqr[i], sqr[i - j * j] + 1);
        }
    }
    cout << sqr[n] << endl;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}