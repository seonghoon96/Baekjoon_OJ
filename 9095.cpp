#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 11
int tc;
int n;
int num[MAX];
void input()
{
    cin >> tc;
}

void solution()
{
    int n;
    while (tc--)
    {
        cin >> n;
        memset(num, 0, MAX * sizeof(int));
        num[1] = 1;
        num[2] = 2;
        num[3] = 4;
        for (int i = 4; i <= n; i++)
        {
            num[i] = num[i - 3] + num[i - 2] + num[i - 1];
        }
        cout << num[n] << endl;
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}