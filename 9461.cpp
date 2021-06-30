#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 100 + 1
#define mod 1000000000
#define ll long long
int tc, n;
ll dp[MAX];
void input()
{
    cin >> tc;
}

void solution()
{
    while (tc--)
    {
        cin >> n;
        memset(dp, 0, sizeof(dp));
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 1;
        dp[4] = 2;
        dp[5] = 2;
        for (int i = 6; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 5];
        }
        cout << dp[n] << endl;
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}