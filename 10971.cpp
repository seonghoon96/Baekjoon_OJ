#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 10 + 1
#define mod 1000000000
#define ll long long

void input();
void solution();

int n;
int map[MAX][MAX];
void input()
{
    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> map[i][j];
}

void solution()
{
    int answer = 123456789;
    vector<int> v(n);
    bool blockFlag;
    for(int i=0; i<n; i++)
        v[i] = i+1;
    do{
        int tmp = 0;
        blockFlag = false;
        for(int i=0; i<n-1; i++)
        {
            if(map[v[i]][v[i+1]] != 0)
                tmp += map[v[i]][v[i+1]];
            else {
                blockFlag = true;
                break;
            }
        }
        if(blockFlag == true) {
            continue;
        }
        if(map[v[n-1]][v[0]] != 0){
            tmp += map[v[n-1]][v[0]];
        }
        else continue;

        answer = min(answer, tmp);
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