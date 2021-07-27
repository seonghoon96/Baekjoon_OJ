#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
#define MAX 4000000 + 1
bool isprime[MAX];
vector<int> prime;
int n;
int answer = 0;
void getprime()
{
    for (int i = 2; i <= n; i++)
        isprime[i] = true;
    for (int i = 2; n >= i * i; i++)
    {
        if (isprime[i])
            for (int j = i * 2; j <= n; j += i)
                isprime[j] = false;
        }
    for (int i = 2; i <= n; i++)
        if (isprime[i])
            prime.push_back(i);
}


int main()
{
    cin >> n;
    getprime();
    int low = 0;
    int high = 0;
    int sum = 0;
    while (1)
    {
        
        if(sum >= n)
        {
            sum -= prime[low++];
        }
        else if (high == prime.size())
            break;
        else if (sum < n)
        {
            sum += prime[high++];
        }
        if (sum == n)
            answer++;
    }
    cout << answer;
}

