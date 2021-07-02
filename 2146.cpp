#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 100 + 1
#define mod 1000000000
#define ll long long

int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n;
void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
        }
    }
    memset(visited, 0, sizeof(visited));
}

void DFS(int x, int y, int cnt)
{
    visited[x][y] = true;
    map[x][y] = cnt;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (1 <= nx && nx <= n && 1 <= ny && ny <= n)
        {
            if (!visited[nx][ny] && map[nx][ny])
                DFS(nx, ny, cnt);
        }
    }
}

int BFS(int cnt)
{
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (map[i][j] == cnt && !visited[i][j])
            {
                q.push(make_pair(i, j));
                visited[i][j] = true;
            }

    int result = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int k = 0; k < size; k++)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (1 <= nx && nx <= n && 1 <= ny && ny <= n)
                {
                    if (!visited[nx][ny] && map[nx][ny])
                    {
                        return result;
                    }
                    else if (!visited[nx][ny] && map[nx][ny] == 0)
                    {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
        result++;
    }
    return result;
}

void solution()
{

    int cnt = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!visited[i][j] && map[i][j])
                DFS(i, j, cnt++);

    int answer = 1000000000;
    for (int i = 1; i < cnt; i++)
    {
        memset(visited, 0, sizeof(visited));
        answer = min(answer, BFS(i));
    }
    cout << answer << endl;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}