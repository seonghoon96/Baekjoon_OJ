#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <string>
using namespace std;

deque<int> gear[4];
int testcase;
int spinGear, direction;
int spinDirec[4];

void input()
{

    string s;
    for (int i = 0; i < 4; i++)
    {
        cin >> s;
        for (int j = 0; j < s.size(); j++)
            gear[i].push_back(s[j] - '0');
    }
    cin >> testcase;
}

void positionCheck()    
{
    spinDirec[spinGear] = direction;
    int rightDirect = spinGear + 1;
    int leftDirect = spinGear - 1;
    int rightPrev = gear[spinGear][2];
    int leftPrev = gear[spinGear][6];
    while (rightDirect < 4)
    {
        if(gear[rightDirect][6] != rightPrev)
        {
            spinDirec[rightDirect] = -direction;
            rightPrev = gear[rightDirect++][2];
        }
        else
            break;
    }
    while(leftDirect >= 0)
    {
        if(gear[leftDirect][2] != leftPrev)
        {
            spinDirec[leftDirect] = -direction;
            leftPrev = gear[leftDirect--][6];
        }
        else
            break;
    }
}

void spinningGear()
{
    int tmp;
    for (int i = 0; i < 4; i++)
    {
        if(spinDirec[i] == 1)
        {
            tmp = gear[i][7];
            gear[i].pop_back();
            gear[i].push_front(tmp);
        }
        else if(spinDirec[i] == -1)
        {
            tmp = gear[i][0];
            gear[i].pop_front();
            gear[i].push_back(tmp);
        }
    }
}

void show()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << gear[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void solution()
{
    cout << endl;
    show();
    while (testcase--)
    {
        
        memset(spinDirec, false, sizeof(spinDirec));
        cin >> spinGear >> direction;
        spinGear--;
        positionCheck();
        cout << "spin direction : ";
        for (int i = 0; i < 4; i++)
        {
            cout << spinDirec[i] << " ";
        }
        cout << endl;
        spinningGear();
        show();
    }
    int result = 0;
    int tmp = 1;
    for (int i = 0; i < 4; i++)
    {
        if(gear[i][0] == 1)
            result += tmp;
        tmp *= 2;
    }
    cout << result;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}