#include <bits/stdc++.h>

#define deb(x) cout << (#x) << " is " << (x) << endl
#define nline "\n"
#define read(x) int x; cin>>x
#define SaveTime() ios_base::sync_with_stdio(false);std::cin.tie(NULL)
#define setDecimalPrecision(Precision) fixed<<showpoint<<setprecision(Precision)
typedef long long ll;

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

void PrintBinaryPrefixes(int n, int ones, int zeroes, string out) {
    if (n == 0) {
        cout << out << "\n";
        return;
    }
    string out_1 = out;
    out_1.push_back('1');
    PrintBinaryPrefixes(n-1,ones+1,zeroes,out_1);
    if(ones>zeroes){
        string out_2 = out;
        out_2.push_back('0');
        PrintBinaryPrefixes(n-1,ones,zeroes+1,out_2);
    }
    return;
}

int solve() {
    PrintBinaryPrefixes(4, 0, 0, "");
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
