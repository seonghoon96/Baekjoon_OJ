#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 1000 + 1
#define mod 1000000000
#define ll long long

int n;
int a[MAX];
ll maxSum[MAX];
ll sum;
void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memset(maxSum, 0, sizeof(maxSum));
}

void solution()
{

    sum = 0;
    for (int i = 1; i <= n; i++)
    {
        maxSum[i] = a[i];
        for (int j = 1; j <= i; j++)
        {
            if (a[i] > a[j])
            {
                maxSum[i] = max(maxSum[i], maxSum[j] + a[i]);
            }
            sum = max(sum, maxSum[i]);
        }
    }
    cout << sum << endl;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}