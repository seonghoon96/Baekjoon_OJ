#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 300 + 1
#define mod 1000000000
#define ll long long
int n;
ll stairs[MAX];
ll dp[MAX];
ll sum;
void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> stairs[i];
}

void solution()
{
    memset(dp, 0, sizeof(dp));
    sum = stairs[1];
    dp[1] = stairs[1];
    dp[2] = stairs[1] + stairs[2];
    dp[3] = max(stairs[1] + stairs[3], stairs[2] + stairs[3]);
    for (int i = 4; i <= n; i++)
    {
        dp[i] = max(stairs[i] + stairs[i - 1] + dp[i - 3], stairs[i] + dp[i - 2]);
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