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
}

void solution()
{
    string s;
    cin >> s;

    int i;
    for (i = 0; i < s.size(); i++)

    {
        cout << s[i];
        if (i % 10 == 9)
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