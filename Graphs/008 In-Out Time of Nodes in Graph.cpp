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

vector<int> graph[1001];
bool visited[1001];
int in_time[1001];
int out_time[1001];

int timer = 1;

void InOutTime(int node)
{
    visited[node] = true;
    in_time[node] = timer++;
    for (int i = 0; i < graph[node].size(); ++i)
    {
        int child = graph[node][i];
        if (visited[i] == false)
        {
            InOutTime(child);
        }
    }
    out_time[node] = timer++;
}

void solve()
{
    int nodes, edges;
    cin >> nodes >> edges;

    // clearing adjacency list and resetting visited array for subsequent calls
    for (int i = 1; i < nodes + 1; ++i)
    {
        graph[i].clear();
        visited[i] = false;
        in_time[i] = 0;
        out_time[i] = 0;
    }

    int a, b;
    for (int i = 0; i < edges; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    InOutTime(1);
}

signed main()
{
    SaveTime();
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
