#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
int n;

void input()
{
    cin >> n;
}

void solution()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
            cout << " ";
        for (int j = 0; j < (i + 1) * 2 - 1; j++)
        {
            if (j % 2 == 0)
                cout << "*";
            else
            {
                cout << " ";
            }
        }
        cout << endl;
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