#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 1001

int n;
int value[MAX] = {
    0,
};
void input()
{
    cin >> n;
}

void solution()
{
    value[1] = 1;
    value[2] = 3;
    for (int i = 3; i <= n; i++)
        value[i] = (value[i - 1] + value[i - 2] * 2) % 10007;
    cout << value[n];
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}