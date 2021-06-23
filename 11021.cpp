#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <cstdlib>
using namespace std;
int t;

void input()
{
    cin >> t;
}

void solution()
{
    for (int i = 1; i <= t; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << "Case #" << i << ": " << a + b << endl;
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