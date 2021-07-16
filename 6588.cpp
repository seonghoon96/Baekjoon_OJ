#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
#define MAX 10000001
int num[MAX];
int n ;
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
    while(true)
    {
        cin >> n;
        if(n == 0) break;
        int flag = 0;
        for(int i=0; i<v.size(); i++)
        {
            if(v[i] > n/2) break;
            if(num[n-v[i]]) {
                    cout << n << " = " << v[i] << " + " << num[n-v[i]] << '\n';
                    flag = 1;
                    break;
            }
        }
        if(flag == 0)
            cout << "Goldbach's conjecture is wrong.\n";
    }

    return 0;

}