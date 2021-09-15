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
int subtree_size[10001];

int dfs(int node)
{
    visited[node]=true;
    int curr_size =1;
    for(int child : graph[node]){
        if(visited[child]==false)
        {
            curr_size += dfs(child);
        }
    }
    subtree_size[node]=curr_size;
    return curr_size;
}


void solve()
{
    int nodes,edges;
    cin>>nodes>>edges;
    int a,b;
    for(int i=0;i<edges;++i)
    {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);
    
    for(int i=1;i<nodes+1;++i)
    {
        cout<<subtree_size[i]<<" ";
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
