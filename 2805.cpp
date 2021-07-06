#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1000000
long long tree[MAX];
int n;
long long m;
long long height;
bool get_value(long long h)
{
    long long value = 0;
    for (int i = 0; i < n; i++)
    {
        if (tree[i] > h)
            value += tree[i] - h;
    }
    if (value >= m)
        return true;
    else
        return false;
}
int main()
{
    cin >> n >> m;
    long long start = 1;
    long long end = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> tree[i];
        end = max(end, tree[i]);
    }
    //    sort(tree, tree + n);
    height = 0;
    while (start <= end)
    {
        long long mid = (start + end) / 2;
        if (get_value(mid))
        {
            height = max(height, mid);
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    cout << height << endl;
}
