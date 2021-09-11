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
int visited[1001];

void dfs(int v,vector<int> ar[])
{
    visited[v]=1;
    cout<<v<<" "<<endl;
    for(int i = 0;i < ar[v].size();++i)
    {
        int child = ar[v][i];
        if(visited[child]==0)
        {
            dfs(child,ar);
        }
    }
}

void solve()
{
    int nodes,edges;
    cin>>nodes>>edges;
    vector<int> ar[nodes+1];
    int a,b;
    while(edges--)
    {
        cin>>a>>b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    dfs(1,ar);
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
