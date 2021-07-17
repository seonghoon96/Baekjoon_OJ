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

int n, m, k;

void input();
void solution();


void input()
{
    cin >> n >> m >> k;
}

void solution()
{
    int count = 0;
    int group = n + m - k;
    while(group>=3)
    {
        if(m-1 >=0 && n-2>=0)
        {
            count++;
            m-=1;
            n-=2;
        }
        else break;
        group -= 3;
    }
    cout << count;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}