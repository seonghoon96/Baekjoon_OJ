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

int n;
vector<int> node[MAX];
int parent[MAX];
bool visited[MAX];

void Dfs(int n)
{
    for (int i = 0; i < node[n].size(); i++)
    {
        if (!visited[node[n][i]])
        {
            visited[node[n][i]] = true;
            parent[node[n][i]] = n;
            Dfs(node[n][i]);
        }
    }
}
void input()
{
    cin >> n;
    memset(parent, 0, sizeof(parent));
    memset(visited, 0, sizeof(visited));
    int node1, node2;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> node1 >> node2;
        node[node1].push_back(node2);
        node[node2].push_back(node1);
    }
}

void solution()
{
    visited[1] = true;
    parent[1] = 1;
    Dfs(1);
    for (int i = 2; i <= n; i++)
    {
        cout << parent[i] << "\n";
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