#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 1000 + 1
#define mod 1000000000
#define ll long long

int n;
int card[MAX];
ll dp[MAX];
void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> card[i];
}

void solution()
{
    dp[0] = card[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] = max(dp[i], dp[i - j] + card[j]);
        }
    }
    cout << dp[n];
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}