#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 101
#define mod 1000000000
#define ll long long
int n;
ll num[MAX][11];
void input()
{
    cin >> n;
}

void solution()
{

    for (int i = 1; i < 10; i++)
        num[1][i] = 1;
    num[1][0] = 0;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0)
                num[i][j] = num[i - 1][1] % mod;
            else if (j == 9)
                num[i][j] = num[i - 1][8] % mod;
            else
            {
                num[i][j] = (num[i - 1][j - 1] + num[i - 1][j + 1]) % mod;
                  }
        }
    }
    ll sum = 0;
    for (int i = 0; i < 10; i++)
        sum += num[n][i];
    cout << sum % mod;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}