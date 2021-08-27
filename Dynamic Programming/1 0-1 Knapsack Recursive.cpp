#include <bits/stdc++.h>

#define deb(x) cout << (#x) << " is " << (x) << endl
#define nline "\n"
#define SaveTime()                    \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL)
#define setDecimalPrecision(Precision) fixed << showpoint << setprecision(Precision)
typedef long long ll;

const int MOD = 1000000007;
const float PI = 3.14159265;

using namespace std;
int Knapsack(vector<int> weight, vector<int> val, int W, int n)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (weight[n - 1] <= W)
    {
        return max(val[n - 1] + Knapsack(weight, val, W - weight[n - 1], n - 1), Knapsack(weight, val, W, n - 1));
    }
    else if(weight[n-1]>W)
    {
        return Knapsack(weight,val,W,n-1);
    }
}
void solve()
{
    int W,n;
    cin>>n>>W;
    vector<int> weight(n),val(n);
    for(int i=0;i<n;++i){
        cin>>weight[i];
    }
    for(int i=0;i<n;++i){
        cin>>val[i];
    }
    cout<<Knapsack(weight,val,W,n);
    return;
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
