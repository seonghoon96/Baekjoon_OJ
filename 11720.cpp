#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int n;
int value = 0;
void input()
{
    cin >> n;
}

void solution()
{
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        value += s[i] - '0';
    }
    cout << value << endl;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}