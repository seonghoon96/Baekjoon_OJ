#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 10000 + 1
#define mod 1000000000
#define ll long long

void input();
void solution();

int n;
ll m, sum;
int val[MAX];
int answer;
void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> val[i];
    answer = 0;
}

void dfs(int index, ll s)
{
    if(s == m)
    {
        answer++;
        return;
    }
    else if(s > m || index > n)
        return;
    dfs(index + 1, s + val[index+1]);
}
void solution()
{
    for (int i = 0; i < n; i++)
    {
        dfs(i, val[i]);
    }
    cout << answer;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}