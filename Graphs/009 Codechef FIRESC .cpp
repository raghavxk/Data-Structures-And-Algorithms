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

vector<int> graph[100001];
bool visited[100001];

ll count_of_nodes_in_cc;

void dfs(ll node)
{
    visited[node] = true;
    count_of_nodes_in_cc++;
    for (ll i = 0; i < graph[node].size(); ++i)
    {
        ll child = graph[node][i];
        if (visited[child] == false)
        {
            dfs(child);
        }
    }
}

void solve()
{   
    count_of_nodes_in_cc=0;
    ll nodes, edges;
    cin >> nodes >> edges;

    for (ll i = 1; i < nodes + 1; ++i)
    {
        graph[i].clear();
        visited[i] = false;
    }

    int a, b;
    for (ll i = 0; i < edges; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    ll count_of_connected_components = 0;
    ll leaders = 1;
    for (ll i = 1; i < nodes + 1; ++i)
    {
        
        if (visited[i] == false)
        {   
            count_of_nodes_in_cc = 0;    
            dfs(i);
            count_of_connected_components++;
            leaders = (leaders * count_of_nodes_in_cc) % MOD;
        }
        
    }
    cout << count_of_connected_components << " " << leaders << endl;
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
