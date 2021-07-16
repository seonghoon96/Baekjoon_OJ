#include <iostream>
#include <stack>
using namespace std;

int a, b, m;
stack<int> astack;
stack<int> bstack;
int sum = 0;
int main()
{
    cin >> a >> b >> m;
    int tmp;
    for(int i=0; i<m; i++)
    {
        cin >> tmp;
        astack.push(tmp);
    }
    tmp = 1;
    while(!astack.empty())
    {
        sum += astack.top() * tmp;
        tmp *= a;
        astack.pop();
    }
    while(sum)
    {
        bstack.push(sum % b);
        sum /= b;
    }
    while(!bstack.empty())
    {
        cout << bstack.top() << " ";
        bstack.pop();
    }

}