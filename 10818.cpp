#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 10000000
int n;
int tmp;
int value[MAX];
void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
}

void solution()
{
    sort(value, value + n);
    cout << value[0] << endl
         << value[n - 1];
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}