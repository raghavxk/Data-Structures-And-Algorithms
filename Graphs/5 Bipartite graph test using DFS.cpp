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
int color_of_node[10001];

bool IsBipartite(int v, int color)
{
    visited[v] = true;
    color_of_node[v] = color;
    for (int i = 0; i < graph[v].size(); ++i)
    {
        int child = graph[v][i];
        if (visited[child] == false)
        {
            if (IsBipartite(child, color ^ 1) == false)
            {
                return false;
            }
        }
        else if (color_of_node[child] == color_of_node[v])
        {
            return false;
        }
    }
    return true;
}
void solve()
{
    int nodes, edges;
    cin >> nodes >> edges;
    int a, b;
    while (edges--)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bool ans = IsBipartite(1, 0);

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
