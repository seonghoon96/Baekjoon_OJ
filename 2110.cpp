#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 200000 + 1
#define mod 1000000000
#define ll long long

int house[MAX];
bool visited[MAX];
int n, c;
int leftc, rightc;
vector<int> position;
void input()
{
    cin >> n >> c;
    for (int i = 0; i < n; i++)
        cin >> house[i];
}

int binary_search(int l, int r)
{
    int mid = (l + r) / 2;
    if (l >= r)
    {
        visited[mid] = true;
        if (house[mid] - house[leftc] > house[rightc] - house[mid])
            rightc = mid;
        else
            leftc = mid;
    }
    else
    {

        if (house[mid] - house[l] > house[r] - house[mid])
        {
            binary_search(l, mid);
        }
        else
        {
            binary_search(mid, r);
        }
    }
    return mid;
}

void solution()
{
    memset(visited, 0, sizeof(visited));
    visited[0] = visited[n - 1] = true;
    leftc = 0;
    rightc = n - 1;
    position.push_back(0);
    position.push_back(n - 1);
    cout << leftc << ", " << rightc << endl;
    sort(house, house + n);
    cout << "house : ";
    for (int i = 0; i    < n; i++)
    {
        cout << house[i] << " ";
    }
    cout << endl;
    if (c <= 2)
    {
        cout << house[n - 1] - house[0] + 1;
        return;
    }
    c -= 2;
    int nextPosition;
    while (c--)
    {
        nextPosition = binary_search(leftc, rightc);
        cout << "nextPos : " << nextPosition << endl;
        position.push_back(nextPosition);
    }
    sort(position.begin(), position.end());

    int answer = house[n - 1] - house[0];
    cout << "answer : " << answer << endl;
    for (int i = 1; i < position.size(); i++)
    {
        if (house[position[i]] - house[position[i - 1]] < answer)
            answer = house[position[i]] - house[position[i - 1]];
    }
    cout << answer;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}