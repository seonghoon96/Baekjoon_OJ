#include <iostream>
using namespace std;

string s;
string answer = "";


string get_binary(int a)
{
    string answer1 = "";

    if( a >=4) answer1 += "1";
    else answer1 += "0";
    a %= 4;
    if(a >= 2) answer1 += "1";
    else answer1 += "0";
    a%= 2;
    if(a >= 1) answer1 += "1";
    else answer1 += "0" ;

    return answer1;

}
int main()
{

    cin >> s;
    int flag = false;
    int tmp = s[0] - '0';
    if(tmp >=4){
        answer += "1";
        flag = true;
    }
    tmp %= 4;
    if(tmp >= 2)
    {
        answer += "1";
        flag = true;
    }
    else if(flag == true)
    {
        answer += "0";
    }
    tmp %= 2;
    if(tmp == 1)
    {
        answer += "1";       
    }
    else {
        answer += "0";
    }
    for(int i=1; i<s.size(); i++)
    {
        string part = get_binary(s[i]-'0');
        answer += part;
    }    
    cout << answer;
}