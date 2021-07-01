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

int n;
vector<pair<int, int>> v;
vector<string> s;
void input()
{
    cin >> n;
    int year;
    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> year >> str;
        v.push_back({year, i});
        s.push_back(str);
    }
}

void solution()
{
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        cout << v[i].first << " " << s[v[i].second] << endl;
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