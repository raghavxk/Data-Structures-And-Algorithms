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

bool dp[102][1002];

void solve()
{
    int n, sum = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        sum += v[i];
    }
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < sum + 1; ++j)
        {
            if (v[i - 1] < sum)
            {
                dp[i][j] = dp[i - 1][j - v[i - 1]] or dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    // print dp
    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < sum + 1; ++j)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    int to_check, count_to_substract = 0;
    cin >> to_check;
    int count = 0;
    for (int i = 0; i < n + 1; ++i)
    {
        if (dp[i][to_check] == true)
        {
            ++count;
        }
    }
    cout << count << endl;
}

signed main()
{
    SaveTime();
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    for (int i = 0; i < 103; ++i)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i < 1003; ++i)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i < 103; ++i)
    {
        for (int j = 1; j < 1003; ++j)
        {
            dp[i][j] = 0;
        }
    }
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
