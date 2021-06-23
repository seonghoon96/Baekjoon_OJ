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
    while (t-- > 0)
    {
        string s;
        cin >> s;
        int a = atoi(&s[0]);
        int b = atoi(&s[2]);
        cout << a + b << endl;
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