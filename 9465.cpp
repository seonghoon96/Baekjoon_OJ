#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 100000 + 1
#define mod 1000000000
#define ll long long

int tc;
int n;
ll table[2][MAX];
ll score[2][MAX];
void input()
{
    cin >> tc;
}

void init()
{
    cin >> n;
    memset(table, 0, sizeof(table));
    for (int i = 1; i <= n; i++)
        cin >> table[0][i];
    for (int i = 1; i <= n; i++)
        cin >> table[1][i];
}
void solution()
{
    while (tc--)
    {
        init();
        for (int i = 2; i <= n; i++)
        {
            table[1][i] = max(table[1][i] + table[0][i - 1], table[1][i - 1]);
            table[0][i] = max(table[0][i] + table[1][i - 1], table[0][i - 1]);
        }
        cout << max(table[1][n], table[0][n]) << endl;
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