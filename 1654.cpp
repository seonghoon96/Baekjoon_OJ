#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 1000000
#define ll long long
ll lan[MAX];
int n, k;
ll low, high, mid;
ll result;
void input()
{
    cin >> n >> k;
    low = 1;
    high = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> lan[i];
        high = max(high, lan[i]);
    }
}

bool check(int value)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += lan[i] / value;
    }
    if (sum >= k)
        return true;
    else
        return false;
}

void solution()
{
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (check(mid))
        {
            if (result < mid)
                result = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << result << endl;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}