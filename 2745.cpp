#include <iostream>
using namespace std;

string s;
int b;

int main()
{
    int result = 0;
    int tmp = 1;
    cin >> s >> b;
    for(int i=0; i<s.size(); i++)
    {
        if(s[s.size() - i - 1] >= '0' && s[s.size() - i - 1] <= '9')
            result += (s[s.size() - i - 1] - '0')* tmp;
        else
        {
            result += (s[s.size() - i - 1] - 'A' + 10) * tmp;
        }
        tmp *= b;
    }
    cout << result;
}