#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 10000+1
#define mod 1000000000
#define ll long long

int n;
bool check[MAX];
void input();
void solution();

void input()
{
    memset(check, false, sizeof(check));
}

void solution()
{
    for (int i = 1; i <= 10000; i++)
    {
        if(check[i] == false)
            cout << i << '\n';
        int tmp = i;
        int result = i;
        while(tmp)
        {
            result += tmp % 10;
            tmp /= 10;
        }
        if(result <=10000) 
            check[result] = true;
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