#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
#define MAX 1001
int num[MAX];
int n;

int main()
{
    for(int i=1; i<=MAX-1; i++)
        num[i] = i;

    cin >> n;
    for(int i=2; i<=MAX; i++)
    {
        if(num[i] == 0) continue;
        for(int j = 2*i; j<=MAX-1; j+= i)
        {
            num[j] = 0;
        }
    }    
    int tmp, count = 0;
    for(int i=0; i<n; i++)
    {
        cin >> tmp;
        if(num[tmp] && tmp != 1) count++;
    }
    cout << count;
    return 0;

}