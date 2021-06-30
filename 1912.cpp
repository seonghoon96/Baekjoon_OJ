#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100000 + 1
#define ll long long
int n;
ll val[MAX];
ll dp[MAX];
ll sum;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
        dp[i] = val[i];
    }
    sum = dp[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i - 1] + val[i], dp[i]);
        sum = max(sum, dp[i]);
    }
    cout << sum << endl;
    return 0;
}