// 문제 제목 : 테트로미노

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 501
#define mod 1000000000
#define ll long long

// global variable
    int n, m;
    int result;
    vector<vector<int>> board;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

    //

    void input();
    void solution();

    void input()
    {
        cin >> n >> m;
        board = vector<vector<int>>(n, vector<int>(m));
        result = 4;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> board[i][j];

}

int case1(int x, int y)
{ // ㅏ
    return board[x][y] + board[x + 1][y] + board[x + 1][y + 1] + board[x + 2][y];
}
int case2(int x, int y)
{ // ㅓ
    return board[x][y] + board[x + 1][y+1] + board[x][y+1] + board[x-1][y+1];
}
int case3(int x, int y)
{ // ㅗ
    return board[x][y] + board[x][y+1] + board[x][y+2] + board[x-1][y+1];
}
int case4(int x, int y)
{ // ㅜ
    return board[x][y] + board[x][y+1] + board[x + 1][y + 1] + board[x][y+2];
}

void dfs(int x, int y, int count, bool visited[MAX][MAX], int sum)
{
    if(count == 4)
    {
        result = max(sum, result);
        return;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx and nx < n and 0 <= ny and ny < m)
            {
                if (!visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    dfs(nx, ny, count + 1, visited, sum + board[nx][ny]);
                    visited[nx][ny] = false;
                }
            }
        }
    }
    
}

void solution()
{
    bool visited[MAX][MAX];
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            memset(visited, false, sizeof(visited));
            visited[i][j] = true;
            dfs(i, j, 1, visited, board[i][j]);
            if(i + 2 < n and j + 1 < m) // ㅏ ㅓ ㅗ ㅜ
                result = max(result, case1(i, j));
            if (i + 1 < n and i-1>=0 and j+1 < m)
                result = max(result, case2(i, j));
            if (i - 1 >= 0 and j + 2 < m)
                result = max(result, case3(i, j));
            if (i + 1 < n and j + 2 < m)
                result = max(result, case4(i, j));
        }
    }
    cout << result << endl;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}