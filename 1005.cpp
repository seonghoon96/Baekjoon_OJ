#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#define MAX 1001
using namespace std;
int test, n, k, last, result, usetime[MAX], sumtime[MAX], complete[MAX];
vector<int> v[MAX];

void input()
{
    memset(complete, false, sizeof(complete));
    memset(v, false, sizeof(v));
    memset(usetime, false, sizeof(usetime));
    int x, y;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> usetime[i];
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y;
        v[y].push_back(x);
    }
    cin >> last;
}

int getresult(int s, int total)
{
    if (v[s].size() == 0)
    {
        complete[s] = true;
        sumtime[s] = usetime[s];
        return usetime[s];
    }
    else
    {
        int maximum = 0;
        for (int i = 0; i < v[s].size(); i++)
        {
            if (complete[v[s][i]] == true)
                maximum = max(maximum, sumtime[v[s][i]]);
            else
            {
                maximum = max(maximum, getresult(v[s][i], total));
            }
        }
        complete[s] = true;
        sumtime[s] = maximum + usetime[s];
        return maximum + usetime[s];
    }
}

void solution()
{
    cout << getresult(last, 0) << endl;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> test;
    while (test--)
    {
        input();
        solution();
    }
    return 0;
}