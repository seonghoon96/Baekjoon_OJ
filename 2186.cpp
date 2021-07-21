#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 101

string space[MAX];
string target;
int n, m, k;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int answer = 0;
void input();
void solution();

void input()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> space[i];
    cin >> target;
    
}

void BFS(int x, int y)
{
    queue < pair<pair<int, int>, int>> q;
    q.push({{x, y}, 1});
    int size = target.size();
    while (!q.empty())
    {
        int xpos = q.front().first.first;
        int ypos = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        if (cnt == size)
        {
            answer++;
            continue;
        }
        else if(cnt >size)
            continue;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                int nx = xpos + dx[i] * j;
                int ny = ypos + dy[i] * j;
                if (0 <= nx && nx < n && 0<=ny && ny<m && space[nx][ny] == target[cnt])
                {
                    q.push({ {nx, ny}, cnt+1});
                }
            }
        }
        
    }
}
void solution()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(space[i][j] == target[0])
            {
                BFS(i, j);
            }
        }
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