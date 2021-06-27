#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 10000 + 1
#define mod 1000000000
#define ll long long
ll grape[MAX];
ll sum[MAX];
int n;
// 포도주
ll max(ll a, ll b, ll c)
{
    if (a >= b && a >= c)
        return a;
    else
    {
        if (b > c)
            return b;
        else
            return c;
    }
}
void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> grape[i];
    }
}

void solution()
{
    sum[0] = 0;

    sum[1] = grape[1];
    if (n >= 2)
        sum[2] = grape[1] + grape[2];
    for (int i = 3; i <= n; i++)
    {
        sum[i] = max(sum[i - 1], sum[i - 2] + grape[i], sum[i - 3] + grape[i - 1] + grape[i]);
    }
    cout << sum[n];
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}