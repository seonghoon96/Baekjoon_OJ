#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 101
#define mod 1000000000
#define ll long long

void input();
void solution();
int compute;
int n;
vector<int> v[MAX];
int graph[MAX][MAX];
bool visited[MAX];
void input()
{
    cin >> compute >> n;
    memset(graph, false, sizeof(graph));
    memset(visited, false, sizeof(visited));
    int spot1, spot2;
    for (int i = 0; i < n; i++)
    {
        cin >> spot1 >> spot2;
        graph[spot1][spot2] = graph[spot2][spot1] = 1;
        v[spot1].push_back(spot2);
        v[spot2].push_back(spot1);
    }
}

void solution()
{
    int count = 0;
    queue<int> q;
    visited[1] = true;
    q.push(1);
    while(!q.empty())
    {
        int pos = q.front();
        q.pop();
        for (int i = 0; i < v[pos].size(); i++)
        {
            int next = v[pos][i];
            if(!visited[next])
            {
                q.push(next);
                visited[next] = true;
                count++;
            }
        }
    }
    cout << count << endl;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}