#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#define MAX 20
using namespace std;

int c, r;
char board[MAX][MAX];
//bool visited[MAX][MAX];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int max_alpa = 0;

map<char, int> m;

void check_board(int x, int y, map<char, int> m)
{
    max_alpa = max(max_alpa, (int)m.size());
}
void BFS(map<char, int> m)
{
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    m['C'] = 1;
    while (!q.empty())
    {
        int xpos = q.front().first;
        int ypos = q.front().second;
        //        visited[xpos][ypos] = true;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = xpos + dx[i];
            int ny = ypos + dy[i];
            if (0 <= nx && nx < c && 0 <= ny && ny <= r && !m[board[xpos][ypos]])
            {
                //                visited[xpos][ypos] = true;
                m[board[xpos][ypos]] = 1;
                check_board(nx, ny, m);
                q.push(make_pair(nx, ny));
            }
        }
    }
}
int main()
{
    cin >> c >> r;
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cin >> board[i][j];
        }
    }
    BFS(m);
}