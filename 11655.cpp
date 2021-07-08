#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    if(s.length() == 0) return 0;
    for(int i=0; i<s.length(); i++)
    {
        char c = s[i];
        int tmp;
        if(c >='a' && c<='z')
        {
            tmp = c - 'a';
            tmp = (tmp + 13)%26;
            s[i] = 'a' + tmp;
        }
        else if(c>='A' && c<='Z')
        {
            tmp = c-'A';
            tmp = (tmp+13)%26;
            s[i] = 'A' + tmp;
        }
    }
    for(int i=0; i<s.length(); i++)
    cout << s[i];
    cout << endl;
}