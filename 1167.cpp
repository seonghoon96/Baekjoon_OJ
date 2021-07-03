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

vector<pair<int, int>> v[MAX];
bool visited[MAX];
int d[MAX];
int n;
void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int start, dest, value;
        cin >> start;
        while (true)
        {
            cin >> dest;
            if (dest == -1)
                break;
            cin >> value;
            v[start].push_back({dest, value});
        }
    }
}

void BFS(int node)
{
    memset(d, 0, sizeof(d));
    memset(visited, 0, sizeof(visited));
    ll result = 0;
    queue<int> q;
    visited[node] = true;
    q.push(node);
    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();
        for (int i = 0; i < v[vertex].size(); i++)
        {
            int nextStep = v[vertex][i].first;
            if (!visited[nextStep])
            {
                int next_distance = v[vertex][i].second;
                visited[nextStep] = true;
                d[nextStep] = d[vertex] + next_distance;
                q.push(nextStep);
            }
        }
    }
}

void solution()
{
    BFS(1);
    int start = 1;
    for (int i = 2; i <= n; i++)
    {
        if (d[i] > d[start])
            start = i;
    }
    BFS(start);
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