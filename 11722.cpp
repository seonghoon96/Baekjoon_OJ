#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 1000 + 1
#define mod 1000000000
#define ll long long

int n;
int a[MAX];
ll len[MAX];
ll answer;
void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memset(len, 0, sizeof(len));
}

void solution()
{

    answer = 0;
    for (int i = n; i >= 1; i--)
    {
        len[i] = 1;
        for (int j = n; j >= i; j--)
        {
            if (a[i] > a[j])
            {
                len[i] = max(len[i], len[j] + 1);
            }
            answer = max(answer, len[i]);
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