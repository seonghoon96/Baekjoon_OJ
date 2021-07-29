#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define mod 1000000000
#define MAX 50 + 1
int n;
vector<int> a, b;

void input();
void solution();

bool cmp(int a, int b)
{
    if (a > b)
        return true;
    return false;
}
void input()
{
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a.push_back(-tmp);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        b.push_back(tmp);
    }
}

void solution()
{
    long long sum = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    for (int i = 0; i < b.size(); i++)
    {
        sum -= a[i] * b[i];
    }
    cout << sum;

}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}