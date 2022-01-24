#include <bits/stdc++.h>

#define deb(x) cout << (#x) << " is " << (x) << endl
#define nline "\n"
#define read(x) int x; cin>>x
#define SaveTime() ios_base::sync_with_stdio(false);std::cin.tie(NULL)
#define setDecimalPrecision(Precision) fixed<<showpoint<<setprecision(Precision)
typedef long long int ll;

const int MOD = 1000000007;

using namespace std;

void printVect(vector<int> vi) {
    ll size = vi.size();
    for (ll i = 0; i < size; ++i) {
        cout << vi[i] << " ";
    }
    cout << nline;
}
set<string> s;
void print_subsets(string input, string output) {
    if (input.length() == 0) {
        s.insert(output);
        return;
    }
    string op_1 = output;
    string op_2 = output;
    op_2.push_back(input[0]);
    input.erase(input.begin() + 0);
    print_subsets(input, op_1);
    print_subsets(input, op_2);
    return;
}

int solve() {
    print_subsets("abc", "");
    for(auto it = s.begin();it!= s.end();++it){
        cout<<*it<<nline;
    }
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
