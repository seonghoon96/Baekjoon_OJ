#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 101
#define ll long long

void input();
void solution();

struct{
    int x, y, h;
} typedef tomato;

int m, n, h;
int box[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dh[6] = {0, 0, 0, 0, 1, -1};

void print()
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
                cout << box[i][j][k] << " ";
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;
}

vector<tomato> v;

void input()
{
    cin >> m >> n >> h;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++)
            {
                cin >> box[i][j][k];
                if(box[i][j][k] == 1)
                {
                    tomato t;
                    t.h = i;
                    t.y = j;
                    t.x = k;
                    v.push_back(t);
                }
            }

}


bool positionCheck(int cx, int cy, int ch)
{
    if(0<=cx && cx<m && 0<=cy && cy<n && 0<=ch && ch< h)
        return true;
    return false;
}


int competeCheck()
{
    int mindate = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++)
            {
                if(box[i][j][k] == 0)
                    return -1;
                else
                    mindate = max(mindate, box[i][j][k]);
                
            }
    return mindate;
}
void BFS()
{
    queue<tomato> q;
    tomato t;
    for (int i = 0; i < v.size(); i++)
    {
        t.x = v[i].x;
        t.y = v[i].y;
        t.h = v[i].h;
        visited[t.h][t.y][t.x] = true;
        q.push(t);
    }
    while (!q.empty())
    {
        int xpos = q.front().x;
        int ypos = q.front().y;
        int hpos = q.front().h;
        q.pop();
        // cout << "front : " << xpos << ", " << ypos << ", " << hpos << " date : " << box[hpos][ypos][xpos] << endl;
        // print();

        for (int i = 0; i < 6; i++)
        {
            int nx = xpos + dx[i];
            int ny = ypos + dy[i];
            int nh = hpos + dh[i];
            if(positionCheck(nx, ny, nh) && !visited[nh][ny][nx] && box[nh][ny][nx] == 0)
            {
                visited[nh][ny][nx] = true;
                box[nh][ny][nx] = box[hpos][ypos][xpos] + 1;
                tomato next;
                next.x = nx;
                next.y = ny;
                next.h = nh;
                q.push(next);
//                cout << "push (" << nx << ", " << ny << ", " << nh << "!!!" << endl;
            }
        }
    }
}
void solution()
{
    BFS();

    int answer = competeCheck();
    if (answer == -1)
        cout << "-1\n";
    else if(answer == 1)
        cout << "0\n";
    else
        cout << answer-1;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}