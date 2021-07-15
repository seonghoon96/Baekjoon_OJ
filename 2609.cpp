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

void input();
void solution();
int g;
int m, n;

int lcm(int a, int b)
{
    return a * b / g;

}
int  gcd(int a, int b)
{
    int tmp;
    if(b<a){
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
    g = a;
    return a;
}

void input()
{
    cin >> m >> n;
}

void solution()
{
    cout<< gcd(m,n) << endl << lcm(m,n) << endl;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}