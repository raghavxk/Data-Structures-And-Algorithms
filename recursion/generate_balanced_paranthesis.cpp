#include <bits/stdc++.h>

#define deb(x) cout << (#x) << " is " << (x) << endl
#define nline "\n"
#define read(x) int x; cin>>x
#define SaveTime() ios_base::sync_with_stdio(false);std::cin.tie(NULL)
#define setDecimalPrecision(Precision) fixed<<showpoint<<setprecision(Precision)
typedef long long int ll;

const int MOD = 1000000007;

using namespace std;

void PrintVect(vector<int> vi) {
    ll size = vi.size();
    for (ll i = 0; i < size; ++i) {
        cout << vi[i] << " ";
    }
    cout << nline;
    return;
}

void BalancedParenthesis(string output, int open, int closed) {
    if (closed == 0 && open == 0) {
        cout << output << nline;
        return;
    }

    if (open != 0) {
        string out_1 = output;
        out_1.push_back('(');
        BalancedParenthesis(out_1, open - 1, closed);
    }
    if (closed > open) {
        string out_2 = output;
        out_2.push_back(')');
        BalancedParenthesis(out_2, open, closed - 1);
    }
    return;

}

int solve() {
    BalancedParenthesis("", 3, 3);
    return 0;
}

int main() {
    SaveTime();
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif

    int T = 1;
    cin >> T;
    while (T--)
        solve();

    return 0;
}
