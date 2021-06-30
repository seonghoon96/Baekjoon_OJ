#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 5000 + 1
#define mod 1000000
#define ll long long
string s;
int str[MAX];
ll dp[MAX];
int strSize;
void input()
{
    cin >> s;
    strSize = s.size();
    for (int i = 0; i < strSize; i++)
        str[i + 1] = s[i] - '0';
}

void solution()
{
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= strSize; i++)
    {
        if (1 <= str[i] && str[i] <= 9)
            dp[i] = (dp[i] + dp[i - 1]) % mod;
        else
        {
            if (str[i - 1] == 0 || str[i - 1] >= 3)
            {
                cout << 0 << endl;
                return;
            }
        }
        if (i == 1)
            continue;
        if (str[i - 1] == 2)
        {
            if (str[i] <= 6)
                dp[i] = (dp[i] + dp[i - 2]) % mod;
        }
        else if (str[i - 1] == 1)
        {
            dp[i] = (dp[i] + dp[i - 2]) % mod;
        }
    }
    cout << dp[strSize] << endl;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}