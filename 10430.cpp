#include <iostream>
using namespace std;

int a, b, c;
int main()
{
    cin >> a >> b >> c;
    cout << (a+b)%c << endl;
    cout << ((a%c) + b%c)%c << endl;
    cout << (a*b)%c << endl;
    cout << ((a%c) * (b%c)) % c << endl;
}