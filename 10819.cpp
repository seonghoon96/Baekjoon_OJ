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

int n;

void input();
void solution();

vector<int> v;
void input()
{
    cin >> n;
    int tmp;
    for(int i=0; i<n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    
}

void solution()
{
    int answer  = 0;
    sort(v.begin(), v.end());
    do {
        int tmp = 0;
        for(int i=0; i<n-1; i++)
            tmp += abs(v[i] - v[i+1]);
        answer = max(answer, tmp);

    } while(next_permutation(v.begin(), v.end()));
    cout << answer;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}