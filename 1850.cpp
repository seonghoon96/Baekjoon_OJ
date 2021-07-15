#include <iostream>
using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    long long tmp;
    while(b)
    {
        tmp = a%b;
        a = b;
        b = tmp;
    }
    for(int i=0; i<a; i++)
    cout << 1;
}