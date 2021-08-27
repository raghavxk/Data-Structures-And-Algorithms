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

// Code starts here!

int dp[1002][1002];

int Knapsack(vector<int> weight, vector<int> value, int n, int W)
{
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < W + 1; ++j)
        {
            if (weight[i - 1] <= j)
            {
                dp[i][j] = max(value[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][W];
}

void solve()
{
    int W, n;
    cin >> n >> W;
    vector<int> weight(n), val(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> val[i];
    }
    cout << Knapsack(weight, val, n, W);

    return;
}

signed main()
{
    SaveTime();
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    // for (int i = 0; i < 1003; ++i)
    // {
    //     dp[0][i] = 0;
    // }
    // for (int i = 0; i < 1003; ++i)
    // {
    //     dp[i][0] = 0;
    // }
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
