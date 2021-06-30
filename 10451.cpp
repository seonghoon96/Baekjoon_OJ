#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 1000 + 1
#define mod 1000000000
#define ll long long

int tc;
int n;
int cycle;
bool visited[MAX];
int v[MAX];

void BFS(int ver)
{
    queue<int> q;
    q.push(ver);
    visited[ver] = true;
    int nv;
    while (!q.empty())
    {
        nv = v[q.front()];
        q.pop();
        if (!visited[nv])
        {
            visited[nv] = true;
            q.push(nv);
        }
    }
    if (ver == nv)
        cycle++;
}
void input()
{
    memset(visited, 0, sizeof(visited));
    memset(v, 0, sizeof(v));
    cycle = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
}

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            BFS(i);
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> tc;
    while (tc--)
    {
        input();
        solution();
        cout << cycle << endl;
    }
    return 0;
}