#include <iostream>
using namespace std;

int tc, a, b;
int main()
{
    cin >> tc;
    while(tc--)
    {
        cin >> a >> b;
        int tmp;
        if(a < b) {
            tmp = a;
            a = b;
            b = tmp;
        }
        int tmpa = a;
        int tmpb = b;
        while(tmpb)
        {
            tmp = tmpa%tmpb;
            tmpa = tmpb;
            tmpb = tmp;
        }
        cout << a * b / tmpa << endl;
    }

}