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
int visited[10001];

void dfs(int v)
{
    visited[v] = 1;
    for (int i = 0; i < graph[v].size(); ++i)
    {
        int child = graph[v][i];
        if (visited[child] == false)
        {
            dfs(child);
        }
    }
}

void solve()
{
    int nodes, edges;
    cin >> nodes >> edges;
    int a, b;
    for (int i = 0; i < edges; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // checkcing for cycle

    if (edges != nodes - 1)
    {
        cout << "NO" << endl;
        return;
    }
    else
    {
        int cc_count = 0;
        for (int i = 1; i < nodes + 1; ++i)
        {
            if (visited[i] == 0)
            {
                cc_count++;
                dfs(i);
            }
        }
        if (cc_count == 1)
        {
            cout << "YES" << endl;
            return;
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
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
