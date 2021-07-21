#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 201
int a, b, c;
vector<int> v;
bool visited[MAX][MAX][MAX];
struct store
{
    int a;
    int b;
    int c;
} typedef store;

int main()
{
    cin >> a >> b >> c;
    queue<pair<pair<int,int>,int>> q;
    q.push({{0, 0}, c});
    while (!q.empty())
    {
        int na = q.front().first.first;
        int nb = q.front().first.second;
        int nc = q.front().second;
        q.pop();
        if (visited[na][nb][nc])
            continue;

        visited[na][nb][nc] = true;

        if(na == 0)
            v.push_back(nc);

        // a - b
        if (na + nb > b)
            q.push({{na - b + nb ,b },nc });
        else
        {
            q.push({{0, na + nb}, nc});
        }
        // a - c
        if(na + nc > c)
        {
            q.push({{na - c + nc, nb}, c});
        }
        else
        {
            q.push({{0, nb}, nc + na});
        }
        // b - a
        if(na + nb > a)
        {
            q.push({{a, -a + na + nb}, nc});
        }
        else
        {
            q.push({{na + nb, 0}, nc});
        }
        // b - c
        if(nb + nc > c)
        {
            q.push({{na, nb - c + nc}, c});
        }
        else
        {
            q.push({{na, 0}, nb + nc});
        }
        
        // c - a
        if(na + nc > a)
        {
            q.push({{a, nb}, nc - a + na});
        }
        else
        {
            q.push({{na + nc, nb}, 0});
        }
        // c - b
        if(nc + nb > b)
        {
            q.push({{na , b}, nc - b + nb});
        }
        else
        {
            q.push({{na, nb+ nc}, 0});
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
