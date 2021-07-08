#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 101
#define mod 1000000000
#define ll long long

void input();
void solution();
string s;
int alpha[26];
void input()
{
    cin >> s;
    memset(alpha, 0, sizeof(alpha));

    for (int i = 0; i < s.size(); i++)
    {
        alpha[s[i] - 'a']++;
    }
}

void solution()
{
    for (int i = 0; i < 26; i++)
        cout << alpha[i] << " ";
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}