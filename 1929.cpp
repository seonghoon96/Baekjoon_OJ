#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
#define MAX 10000001
int num[MAX];
int n, m;

int main()
{
    for(int i=1; i<=MAX-1; i++)
        num[i] = i;
    num[0] = num[1] = 0;
    for(int i=2; i<=sqrt(MAX-1); i++)
    {
        if(num[i] == 0) continue;
        for(int j = 2*i; j<=MAX-1; j+= i)
        {
            num[j] = 0;
        }
    }    
    cin >> n >> m;
    for(int i=n; i<=m; i++)
    {
        if(num[i]) cout << i << '\n';
    }

    return 0;

}