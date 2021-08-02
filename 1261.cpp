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
const int INF = 987654321;
int n, m;

void input();
void solution();

bool visited[MAX][MAX];
int map[MAX][MAX];
int d[MAX][MAX];
int answer = INF;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void input()
{
    cin >> n >> m;
    string s;
    memset(visited, false, sizeof(visited));
    memset(map, false, sizeof(map));
    memset(d, false, sizeof(d));
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            map[i + 1][j + 1] = s[j] - '0';
            d[i + 1][j + 1] = INF;
        }
    }
}

void BFS()
{
    d[1][1] = 0;
    queue<pair<int, int>> q;
    q.push({1, 1});
    visited[1][1] = true;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=1 && nx<=m && ny >=1 && ny <=n)
            {
                if (map[nx][ny] == 1)
                {
                    if(d[nx][ny] > d[x][y] + 1)
                    {
                        d[nx][ny] = d[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
                else if(map[nx][ny] == 0)
                {
                    if(d[nx][ny] > d[x][y])
                    {
                        q.push({nx, ny});
                        d[nx][ny] = d[x][y];
                    }
                }
            }
        }
    }
}

void solution()
{
    BFS();
    cout << d[m][n];
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}