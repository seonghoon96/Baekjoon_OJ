#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 200 + 1
#define mod 1000000000
#define ll long long
ll N, K;
ll answer = 0;
void input()
{
    cin >> N >> K;
}

void solution()
{
    long dp[MAX][MAX] = {0};
    for (int n = 0; n <= N; n++)
    {
        dp[1][n] = 1;
    }

    for (int k = 2; k <= K; k++)
    {
        for (int n = 0; n <= N; n++)
        {
            for (int l = 0; l <= n; l++)
            {
                dp[k][n] += dp[k - 1][l];
            }
            dp[k][n] %= mod;
        }
    }

    cout << dp[K][N] << endl;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}