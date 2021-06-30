#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 30 + 1
#define mod 1000000000
#define ll long long

int n;
int dp[MAX] = {
    0,
};
void input()
{
    cin >> n;
    memset(dp, 0, sizeof(dp));
}

void solution()
{
    dp[0] = 1;
    dp[2] = 3;
    for (int i = 4; i <= n; i += 2)
    {
        dp[i] = dp[i - 2] * 3;
        for (int j = i - 4; j >= 0; j -= 2)
        {
            dp[i] += dp[j] * 2;
        }
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