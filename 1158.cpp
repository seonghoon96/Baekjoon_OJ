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
int n, k;
void input();
void solution();

vector<int> v;
vector<int> answer;
void input()
{
    cin >> n >> k;
    v.clear();
    answer.clear();

    for(int i=0; i<n; i++)
        v.push_back(i+1);
}

void solution()
{
    int index = 0;
    int count = 1;
    cout << "<";
    while(v.size() != 1)
    {
        index+= k-1;
        index %= v.size();
        cout << v[index] << ", ";
        v.erase(v.begin() + index);

    }
    cout << v[0] << ">\n";
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}