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

// function returns true if a cycle exists in graph, otherwise false 
bool CheckGraphForCycle(int node, int parent)
{
    visited[node] = true;

    for (int i = 0; i < graph[node].size(); ++i)
    {
        int child = graph[node][i];
        if (visited[child] == false)
        {
            if (CheckGraphForCycle(child, node) == true)
            {
                return true;
            }
        }
        else if (child != parent)
        {
            return true;
        }
    }
    return false;
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
    }

    int a, b;
    for (int i = 0; i < edges; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bool ans = CheckGraphForCycle(1, -1);

    cout << ans << endl;
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
