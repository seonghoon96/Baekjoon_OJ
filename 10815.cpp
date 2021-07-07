#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
using namespace std;
#define MAX 500000
int m, n;
int card[MAX];
int list[MAX];
map<int, int> mapping;
void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> card[i];
        mapping[card[i]]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> list[i];
}

bool binary_search(int number)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (card[mid] == number)
            return true;
        else if (card[mid] < number)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}
void solution()
{
    sort(card, card + n);
    for (int i = 0; i < m; i++)
    {
        if (binary_search(list[i]))
            cout << mapping[list[i]] << " ";
        else
            cout << "0 ";
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