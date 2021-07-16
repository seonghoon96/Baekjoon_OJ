#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
#define MAX 10000001
int num[MAX];
vector<int> v;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    for(int i=1; i<=MAX-1; i++)
        num[i] = i;

    num[0] = num[1] = 0;

    for(int i=2; i <= MAX; i++)
    {
        if(num[i] == 0) continue;
        v.push_back(i);
        for(int j = 2*i; j<=MAX-1; j+= i)
            num[j] = 0;
    }    
    int n;
    cin >> n;
    
    while(n>1)
    {
        for(int i=0; i<v.size(); i++)
        {
            if(n%v[i] == 0)
            {
                cout << v[i] << "\n";
                n/=v[i];
                break;
            }
        }
    }

    return 0;

}