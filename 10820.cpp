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
void solution(string s);

int answer[4];
void input()
{
    for(int i=0; i<100; i++)
    {
        string s;
        getline(cin, s);
        if(s.size() == 0) break;
        memset(answer, 0, sizeof(answer));
        solution(s);
    }
}

void solution(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            answer[0]++;
        else if (s[i] >= 'A' && s[i] <= 'Z')
            answer[1]++;
        else if (s[i] >= '0' && s[i] <= '9')

            answer[2]++;
        else if (s[i] == ' ')
            answer[3]++;
    }
    cout << answer[0] << " " << answer[1] << " " << answer[2] << " " << answer[3] << "\n";
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    return 0;
}

