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
int max_distance, max_node;

void dfs(int node,int distance)
{
    visited[node]=true;
    if(distance>max_distance)
    {
        max_distance=distance;
        max_node=node;
    }
    for(int i=0;i<graph[node].size();++i)
    {
        int child = graph[node][i];
        if(visited[child]==false){
            dfs(child,distance+1);
        }
    }
}

void solve()
{
    int nodes;
    cin>>nodes;
    int edges=nodes-1;

    int a,b;
    for(int i=0;i<edges;++i){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    max_distance=-1;
    dfs(1,0);
    max_distance=-1;
    for(int i=1;i<nodes+1;++i)
    {
        visited[i]=false;
    }
    // cout<<max_node<<endl;
    dfs(max_node,0);
    cout<<max_distance<<endl;
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
