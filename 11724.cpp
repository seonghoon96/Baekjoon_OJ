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

int vertex, edge;
int connect = 0;
bool graph[MAX][MAX];
bool visited[MAX];

void BFS(int v)
{
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while (!q.empty())
    {
        int ver = q.front();
        q.pop();
        for (int i = 1; i <= vertex; i++)
        {
            if (graph[ver][i] && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void input()
{
    memset(graph, 0, sizeof(graph));
    cin >> vertex >> edge;
    int v1, v2;
    for (int i = 0; i < edge; i++)
    {
        cin >> v1 >> v2;
        graph[v1][v2] = graph[v2][v1] = true;
    }
}

void solution()
{
    for (int i = 1; i <= vertex; i++)
    {
        if (!visited[i])
        {
            connect++;
            BFS(i);
        }
    }
    cout << connect << endl;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}