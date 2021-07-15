#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define MAX 100

int tc, n;
int numList[MAX];

int getGCD(int a, int b)
{
    int tmp;
    if(b>a){
        tmp = a;
        a = b;
        b = tmp;
    }
    while(b)
    {
        tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}
int main()
{
    cin >> tc;
    while(tc--)
    {
        memset(numList, 0, sizeof(numList));
        long long result = 0;
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> numList[i];
        for(int i=0; i<n; i++)
        {
            for(int j = i+1; j<n; j++)
            {
                int gcd = getGCD(numList[i], numList[j]);
//                if( gcd != 1 )
                    result += gcd;
            }           
        }
        cout << result << endl;
    }
}