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

int dp[102][1002];

bool solve()
{ 
    int n,sum=0;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; ++i)
    {
        cin>>num[i];
        sum += num[i];
    }
    if (sum % 2 != 0)
    {   
        cout<<false<<endl;
        return false;
    }
    else
    {
//       we simply check if half of sum of array is present as any subset or not, because the other half will automatically exist.
        int target = sum / 2;
        for (int i = 1; i < n + 1; ++i)
        {
            for (int j = 1; j < target + 1; ++j)
            {
                if (num[i - 1] < target)
                {
                    dp[i][j] = dp[i - 1][j - num[i - 1]] or dp[i - 1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        bool ans = dp[n][target];
        cout<<ans<<endl;
        return ans;
    }
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
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
