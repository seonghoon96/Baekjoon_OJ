#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 90 + 1
#define mod 1000000000
#define ll long long

int n;
ll num[MAX][2];
void input()
{
    cin >> n;
    num[1][0] = 0;
    num[1][1] = 1;
    num[2][0] = 1;
    num[2][1] = 0;
}

void solution()
{
    for (int i = 3; i <= n; i++)
    {
        num[i][0] = num[i - 1][0] + num[i - 1][1];
        num[i][1] = num[i - 1][0];
    }
    cout << num[n][0] + num[n][1];
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}