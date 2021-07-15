#include <iostream>
using namespace std;

string answer = "";

int main()
{
    int n, b;
    cin >> n >> b;
    while(n)
    {
        int tmp = n%b;
        if(tmp < 10) answer += to_string(tmp);
        else answer += 'A' + tmp - 10;
        n /= b;
    }    
    for(int i=0; i<answer.size(); i++)
    {
        cout << answer[answer.size() - i-1];
    }
}