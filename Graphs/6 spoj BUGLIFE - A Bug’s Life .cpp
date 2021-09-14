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
 
vector<int> graph[2001];
bool visited[2001];
int color_of[2001];
 
bool IsBipartite(int v, int color)
{
    visited[v] = true;
    color_of[v] = color;
    for (ll i = 0; i < graph[v].size(); ++i)
    {
        int child = graph[v][i];
        if (visited[child] == false)
        {
            if (IsBipartite(child, !color) == false)
            {
                return false;
            }
        }
        else if (color_of[child] == color_of[v])
        {
            return false;
        }
    }
    return true;
}
void solve()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        ll nodes, edges;
        cin >> nodes >> edges;
        int a, b;
 
        for (ll j = 1; j < nodes + 1; ++j)
        {
            graph[j].clear();
            visited[j] = 0;
        }
        for (ll j = 0; j < edges; ++j)
        {
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        bool flag = true;
        for (int j = 1; j < nodes; ++j)
        {
            if (visited[j] == false)
            {
                bool result = IsBipartite(j, 0);
 
                if (result == false)
                {
                    flag = false;
                    break;
                }
            }
        }
        cout << "Scenario #" << i + 1 << ":" << endl;
        if (flag == true)
        {
            cout << "No suspicious bugs found!" << endl;
        }
        else
        {
            cout << "Suspicious bugs found!" << endl;
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
 
    // int T = 1;
    // cin >> T;
    // while (T--)
    // {
    //     solve();
    // }
    solve();
    return 0;
} 
