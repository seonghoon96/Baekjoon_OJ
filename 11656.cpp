#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string s;
vector<string> v;

int main()
{
    v.clear();
    cin >> s;
    int size = s.size();
    for(int i=0; i<s.length(); i++)
        v.push_back(s.substr(i, size - i));
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << endl;
    }
    return 0;

}