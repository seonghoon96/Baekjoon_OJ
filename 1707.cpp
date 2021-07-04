#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 20000 + 1
#define mod 1000000000
#define ll long long
int tc;
int ver, edg;
vector<int> v[MAX];
int visited[MAX];
bool answer = true;
vector<int> set[3];

void BFS(int node)
{
    queue<int> q;
    set[1].push_back(node);
    visited[node] = 1;
    q.push(node);
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        // cout << "Front : " << front << ", setNum : " << visited[front] << endl;
        int setNum = 1;
        if (visited[front] == 1)
            setNum = 2;
        for (int i = 0; i < v[front].size(); i++)
        {
            if (!visited[v[front][i]])
            {
                visited[v[front][i]] = setNum;
                set[setNum].push_back(v[front][i]);
                q.push(v[front][i]);
            }
            else if (visited[front] == visited[v[front][i]])
            {
                answer = false;
                return;
            }
        }
    }
}

void solution()
{
    for (int i = 1; i <= ver; i++)
    {
        if (!visited[i])
        {
            set[1].clear();
            set[2].clear();
            BFS(i);
        }
    }
    if (answer)
        cout << "YES\n";
    else
        cout << "NO\n";
}

void input()
{
    cin >> tc;
    while (tc--)
    {
        for (int i = 1; i <= ver; i++)
            v[i].clear();
        memset(visited, 0, sizeof(visited));
        set[1].clear();
        set[2].clear();
        answer = true;
        cin >> ver >> edg;
        int ver1, ver2;
        for (int i = 0; i < edg; i++)
        {
            cin >> ver1 >> ver2;
            v[ver1].push_back(ver2);
            v[ver2].push_back(ver1);
        }
        solution();
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    return 0;
}