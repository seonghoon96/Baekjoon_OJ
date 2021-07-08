#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    string s1 = to_string(a) + to_string(b);
    string s2 = to_string(c) + to_string(d);
    long long answer1 = stoll(s1);
    long long answer2 = stoll(s2);
    cout << answer1 + answer2;
}