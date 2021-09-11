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

bool visited[1001];

void dfs(vector<int> ar[], int v)
{
    visited[v] = true;
    for (int i = 0; i < ar[v].size(); ++i)
    {
        int child = ar[v][i];
        if (visited[child] == false)
        {
            dfs(ar, child);
        }
    }
}
void solve()
{
    int nodes, edges;
    cin >> nodes >> edges;
    vector<int> graph[nodes + 1];
    int a, b;
    while (edges--)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int cc_count = 0;
    for (int i = 1; i < nodes + 1; ++i)
    {
        if (visited[i] == 0)
        {
            dfs(graph, i);
            cc_count++;
        }
    }
    cout << cc_count << endl;
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
