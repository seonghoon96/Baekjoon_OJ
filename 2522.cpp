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
        for (int k = n - 1; k >= 0; k--)
        {
            if (k <= i)
                cout << "*";
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int k = n - 1; k >= 0; k--)
        {
            if (k <= i)
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