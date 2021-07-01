#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 1000000 + 1
#define mod 1000000000
#define ll long long

ll n, p;
vector<ll> v;
queue<ll> q;
bool visited[MAX];

void input()
{
    cin >> n >> p;
    memset(visited, 0, sizeof(visited));
}

ll get_next(ll x)
{
    ll next = 0;
    while (x)
    {
        int tmp = x % 10;
        for (int i = 1; i < p; i++)
            tmp *= x % 10;
        next += tmp;
        x /= 10;
    }
    return next;
}
void solution()
{
    q.push(n);
    visited[n] = true;
    ll tmp = n;
    while (true)
    {
        tmp = get_next(tmp);
        if (visited[tmp])
        {
            break;
        }
        else
        {
            visited[tmp] = true;
            q.push(tmp);
        }
    }

    int count = 0;
    while (!q.empty())
    {
        ll next = q.front();
        if (next == tmp)
            break;
        else
        {
            count++;
            q.pop();
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