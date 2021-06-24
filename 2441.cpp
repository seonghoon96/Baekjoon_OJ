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
    for (int i = n; i > 0; i--)
    {
        for (int j = n; j > 0; j--)
        {
            if (j - i <= 0)
                cout << "*";
            else
                cout << " ";
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