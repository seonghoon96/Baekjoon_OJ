#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
#define MAX 20

int n, s;
int list[MAX];
int answer;

void dfs(int idx, int sum)
{
    sum += list[idx];

    if (idx >= n)
        return;
    if (sum == s)
        answer++;

    dfs(idx + 1, sum - list[idx]);
    dfs(idx + 1, sum);
}
int main()
{
    answer = 0;
    memset(list, false, sizeof(list));
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> list[i];
    }
    dfs(0, 0);
    cout << answer;
}