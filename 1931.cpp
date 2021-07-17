    #include <iostream>
    #include <algorithm>
    #include <cstring>
    #include <cstdio>
    #include <vector>
    #include <cmath>
    #include <queue>
    using namespace std;
    #define MAX 101
    #define mod 1000000000
    #define ll long long

    void input();
    void solution();

    int n, start, e;
    vector<pair<int,int>> v;

    bool cmp(pair<int,int> v1, pair<int,int> v2)
    {
        if(v1.second > v2.second) return true;
        else if(v1.second == v2.second)
        {
            if(v1.first > v1.second) return true;
            else return false;
        }
        return false;
    }

    void input()
    {
        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> start >> e;
            v.push_back({e, start});
        }
        sort(v.begin(), v.end());

    }

    void solution()
    {

        e = 0;
        int count = 0;
        for(int i = 0; i<n; i++)
        {
            if(v[i].second >= e)
            {
                e = v[i].first;
                count++;

            }
        }
        cout << count;
    }

    int main()
    {
        cin.tie(0);
        ios_base::sync_with_stdio(0);
        input();
        solution();
        return 0;
    }