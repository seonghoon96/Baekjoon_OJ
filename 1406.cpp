#include <string>
#include <iostream>
#include <vector>

using namespace std;


string s;
int n;
int cursor;

int main()
{
    cin >> s >> n;
    cursor = s.size();
    string tmp;
    for(int i=0; i<n; i++)
    {
        cin >> tmp;
        
        
        string substr1, substr2;
        if(tmp[0] == 'L')
        {
            if(cursor <= 0) continue;
            else cursor--;
        }
        else if(tmp[0] == 'D')
        {
            if(cursor == s.length()) continue;
            else cursor++;
        }
        else if(tmp[0] == 'B')
        {
            if(cursor <= 0)
                continue;
            substr1 = s.substr(0, cursor-1);
            substr2 = s.substr(cursor);
            s = substr1 + substr2;
            cursor--;
        }
        else
        {
            substr1 = s.substr(0, cursor);
            substr2 = s.substr(cursor);
            s = substr1 + to_string(tmp[2]) + substr2;
            cursor++;
        }
    }
    cout << s;
    return 0;
}