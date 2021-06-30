#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 1000000 + 1
#define mod 1000000000
#define ll long long

int n;
int dp[MAX];
int value[MAX];
int minIndex;
void input()
{
    cin >> n;
    memset(dp, 0, sizeof(dp));
}

void solution()
{
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1;
        if (i % 3 == 0)
            dp[i] = min(dp[i / 3] + 1, dp[i]);
        if (i % 2 == 0)
            dp[i] = min(dp[i / 2] + 1, dp[i]);
    }
    cout << dp[n] << endl;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}