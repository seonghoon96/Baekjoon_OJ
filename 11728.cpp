#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define ll long long


void input();
void solution();

vector<int> v1, v2;
int size1, size2;

void input()
{
    cin >> size1 >> size2;
    int tmp;
    for (int i = 0; i < size1; i++)
    {
        cin >> tmp;
        v1.push_back(tmp);
    }
    for (int i = 0; i < size2; i++)
    {
        cin >> tmp;
        v2.push_back(tmp);
    }
}

void solution()
{
    int p1 = 0, p2 = 0;
    while(p1!=size1 and p2!=size2)
    {
        if(v1[p1] < v2[p2])
            cout << v1[p1++] << " ";
        else
            cout << v2[p2++] << " ";
    }

    if(p1 == size1)
    {
        for (int i = p2; i < size2; i++)
            cout << v2[i] << " ";
    }
    else
    {
        for (int i = p1; i < size1; i++)
            cout << v1[i] << " ";
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