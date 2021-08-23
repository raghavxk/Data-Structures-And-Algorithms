#include <bits/stdc++.h>

#define deb(x) cout << (#x) << " is " << (x) << endl
#define nline "\n"
#define SaveTime() ios_base::sync_with_stdio(false);std::cin.tie(NULL)
#define setDecimalPrecision(Precision) fixed<<showpoint<<setprecision(Precision)
typedef long long ll;

const int MOD = 1000000007;
const float PI = 3.14159265;

using namespace std;

void PrintVect(vector<int> vi) {
    ll size = vi.size();
    for (ll i = 0; i < size; ++i) {
        cout << vi[i] << " ";
    }
    cout << nline;
    return;
}

void josephus(vector<int> &person, int k, int index)
{
    if (person.size() == 1)
    {
        cout << person[0] << nline;
        return;
    }
    index = (index + k) % person.size();
    person.erase(person.begin() + index);
    josephus(person, k, index);
    return;
}

int solve()
{
    int n, k;
    cin >> n >> k;
    k--;
    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        v.push_back(i + 1);
    }
    josephus(v, k, 0);
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
