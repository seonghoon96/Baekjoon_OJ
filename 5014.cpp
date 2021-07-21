    #include <iostream>
    #include <algorithm>
    #include <cstring>
    #include <cstdio>
    #include <vector>
    #include <cmath>
    #include <queue>
    using namespace std;
    #define MAX 1000000 + 1
    #define INF 987654321
    int f, s, g, u, d;
    void input();
    void solution();
    bool visited[MAX];
    int answer = INF;
    // void DFS(int floor, int click)
    // {
    //     visited[floor] = true;
    //     if (floor == g)
    //     {
    //         answer = min(answer, click);
    //         return;
    //     }
    //     if (floor + u > floor && floor + u <= f && !visited[floor + u])
    //     {
    //         DFS(floor + u, click + 1);
    //         visited[floor + u] = false;
    //     }
    //     if (floor - d < floor && floor - d >= 1 && !visited[floor - d])
    //     {
    //         DFS(floor - d, click + 1);
    //         visited[floor - d] = false;
    //     }
    // }

    void input()
    {
        cin >> f >> s >> g >> u >> d;
    }

    void solution()
    {

        bool visit[MAX];
        memset(visit, false, sizeof(visit));
        queue<pair<int, int>> q;
        q.push({s, 0});
        visit[s] = true;

        while (!q.empty())
        {
            int pos = q.front().first;
            int cnt = q.front().second;
            q.pop();
            if(pos == g)
            {
                answer = cnt;
                break;
            }
            if(pos+u <= f && !visit[pos+u])
            {
                visited[pos + u] = true;
                q.push({pos + u, cnt + 1});
            }
            if(pos-d >=1 && !visit[pos-d])
            {
                visit[pos - d] = true;
                q.push({pos - d, cnt + 1});
            }
        }
        if (answer == INF)
            cout << "use the stairs\n";
        else
            cout << answer << endl;
    }

    int main()
    {
        cin.tie(0);
        ios_base::sync_with_stdio(0);
        input();
        solution();
        return 0;
    }