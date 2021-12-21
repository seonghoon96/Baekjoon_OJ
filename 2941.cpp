// 문제 제목 : 크로아티아 알파벳


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

// global variable
string s;
int answer;
//

void input();
void solution();

void input()
{
    cin >> s;
    answer = 0;
}

void solution()
{
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'c' and i+1 < s.size())
        {
            if(s[i+1] == '-' or s[i+1] == '=')
                i++;
        }
        else if (s[i] == 'd')
        {
            if(i+1 < s.size() and s[i+1] == '-')
                i++;
            else if(i+2 < s.size() and s[i+1] == 'z' and s[i+2] == '=')
                i += 2;
        }
        else if (s[i] == 'l' and i+1 < s.size())
        {
            if(s[i+1] == 'j')
                i++;
        }
        else if (s[i] == 'n')
        {
            if(s[i+1] == 'j')
                i++;
        }
        else if (s[i] == 's')
        {
            if (s[i + 1] == '=')
                i++;
        }
        else if (s[i] == 'z')
        {
            if (s[i + 1] == '=')
                i++;
        }
        answer++;
    }
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