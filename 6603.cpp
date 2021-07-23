#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define ll long long
#define MAX 13
void input();
void solution();
int k;
int lotto[MAX];
int answer[6];

void dfs(int indx1, int indx2)
{
    if (indx2 == 6)
    {
        for (int i = 0; i < 6; i++)
        {
            cout << answer[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = indx1; i < k; i++)
    {
        answer[indx2] = lotto[i];
        dfs(i + 1, indx2 + 1);
    }
}

void input()
{
    while (true)
    {
        cin >> k;
        if (k == 0)
            break;
        memset(lotto, false, sizeof(lotto));
        memset(answer, false, sizeof(answer));
        for (int i = 0; i < k; i++)
        {
            cin >> lotto[i];
        }
        dfs(0, 0);
        cout << '\n';
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    return 0;
}