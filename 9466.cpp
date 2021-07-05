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
void input();
void solution();

int tc, n;
int sel[MAX];
bool visited[MAX];
bool done[MAX];
int answer;

void input()
{
    cin >> tc;
    while (tc--)
    {
        memset(sel, 0, sizeof(sel));
        memset(visited, 0, sizeof(visited));
        memset(done, 0, sizeof(done));
        answer = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> sel[i];

        solution();
    }
}

void DFS(int n)
{
    visited[n] = true;
    int node = sel[n];
    if (!visited[node])
    {
        DFS(node);
    }
    else if (!done[node])
    {
        for (int i = node; i != n; i = sel[i])
        {
            answer++;
        }
        answer++;
    }
    done[n] = true;
}

// void BFS(int s)
// {
//     visited[s] = true;
//     queue<int> q;
//     vector<int> team;
//     team.push_back(s);
//     q.push(s);
//     while (!q.empty())
//     {
//         int student = q.front();
//         q.pop();
//         if (!visited[sel[student]])
//         {
//             visited[sel[student]] = true;
//             team.push_back(sel[student]);
//             q.push(sel[student]);
//         }
//         else
//         {
//             for (int i = 0; i < team.size(); i++)
//             {
//                 if (sel[student] == team[i])
//                 {
//                     answer += i;
//                     break;
//                 }
//             }
//             return;
//         }
//     }
// }
void solution()
{
    answer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            DFS(i);
    }
    cout << n - answer << endl;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    return 0;
}