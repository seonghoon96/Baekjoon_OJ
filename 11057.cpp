#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 1000 + 1
#define mod 10007
#define ll long long

int n;
int num[MAX][10];
void input()
{
    cin >> n;
    for (int i = 0; i < 10; i++)
    {
        num[1][i] = 1;
    }
}

void solution()
{
    int sum = 0;
    for (int i = 2; i <= n; i++)
    {
        sum = 0;
        for (int k = 0; k < 10; k++)
        {
            sum = (sum + num[i - 1][k]) % mod;
            num[i][k] = sum % mod;
        }
    }
    int value = 0;
    for (int i = 0; i < 10; i++)
        value = (value + num[n][i]) % mod;
    cout << value;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}