#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 26 + 1
#define mod 1000000000
#define ll long long

struct node
{
    char left;
    char right;
};
int n;
struct node arr[MAX];

void input()
{
    cin >> n;
    char value, left, right;
    for (int i = 0; i < n; i++)
    {
        cin >> value >> left >> right;
        arr[value].left = left;
        arr[value].right = right;
        cout << "position : " << &arr[value] - arr << endl;
    }
}

void preorder(char root)
{
    if (root == '.')
        return;
    cout << root;
    preorder(arr[root].left);
    preorder(arr[root].right);
}
void inorder(char root)
{
    if (root == '.')
        return;
    inorder(arr[root].left);
    cout << root;
    inorder(arr[root].right);
}

void postorder(char root)
{
    if (root == '.')
        return;
    postorder(arr[root].left);
    postorder(arr[root].right);
    cout << root;
}
void solution()
{
    preorder('A');
    cout << endl;
    inorder('A');
    cout << endl;
    postorder('A');
    cout << endl;
}

int main()
{

    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solution();
    return 0;
}