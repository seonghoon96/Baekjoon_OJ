#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 10000 + 1

vector<pair<int, int>> v[MAX];
bool visited[MAX];
int d[MAX];
int n;

void DFS(int node, int dis)
{
    visited[node] = true;
    d[node] = dis;
    for (int i = 0; i < v[node].size(); i++)
    {
        int nextNode = v[node][i].first;
        if (!visited[nextNode])
        {
            d[nextNode] = dis + v[node][i].second;
            DFS(nextNode, dis + v[node][i].second);
        }
    }
}
void input()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int node1, node2, weight;
        cin >> node1 >> node2 >> weight;
        v[node1].push_back({node2, weight});
        v[node2].push_back({node1, weight});
    }
}

void solution()
{
    visited[1] = true;
    DFS(1, 0);
    int maxNode = 1;
    for (int i = 2; i <= n; i++)
        if (d[i] > d[maxNode])
            maxNode = i;

    memset(visited, 0, sizeof(visited));
    memset(d, 0, sizeof(d));
    DFS(maxNode, 0);
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] > answer)
            answer = d[i];
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