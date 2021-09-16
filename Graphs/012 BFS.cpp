#include <bits/stdc++.h>

#define deb(x) cout << (#x) << " is " << (x) << endl
#define endl "\n"
#define SaveTime()                    \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)
#define setDecimalPrecision(Precision) fixed << showpoint << setprecision(Precision)
typedef long long int ll;

const int MOD = 1000000007;
const float PI = 3.14159265;

using namespace std;

// Code starts here !

vector<int> graph[10001];
bool visited[10001];
int sssp[10001];

void BFS(int source)
{
    queue<int> q;
    q.push(source);
    visited[source] = true;
    sssp[source] = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int child : graph[curr])
        {
            if (visited[child] == false)
            {
                q.push(child);
                sssp[child] = sssp[curr] + 1;
                visited[child] = true;
            }
        }
    }
}

void solve()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int nodes, edges;
        cin >> nodes >> edges;
        for (int i = 1; i < nodes + 1; ++i)
        {
            graph[i].clear();
            visited[i] = false;
            sssp[i] = INT_MAX;
        }
        int a, b;
        for (int i = 0; i < edges; ++i)
        {
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        BFS(1);

        cout << sssp[nodes] << endl;
    }
}

signed main()
{
    SaveTime();
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif

    solve();

    return 0;
}
