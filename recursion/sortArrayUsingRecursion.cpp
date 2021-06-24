#include <bits/stdc++.h>
#include <chrono>
#include <ctime>

#define deb(x) cout << (#x) << " is " << (x) << endl
#define nline "\n"
#define read(x) int x; cin>>x
#define fastio() ios_base::sync_with_stdio(false);std::cin.tie(NULL)
typedef long long int ll;

using namespace std;

void insert(vector<int> &v, int temp) {
    if (v.size() == 0 || v[v.size() - 1] <= temp) {
        v.push_back(temp);
        return;
    }
    int val = v[v.size() - 1];
    v.pop_back();
    insert(v, temp);
    v.push_back(val);
    return;
}

void sortMe(vector<int> &v) {
    if (v.size() == 1)
        return;
    int temp = v[v.size() - 1];
    v.pop_back();
    sortMe(v);
    insert(v, temp);
    // v.push_back(temp);
}



int solve() {
    vector<int> v = {8, -1, 7, 6, 5};
    sortMe(v);
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    return 0;
}

int main() {
    fastio();
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    auto start1 = std::chrono::high_resolution_clock::now();
#endif

    int t = 1;
    cin >> t;
    while (t--)
        solve();

#ifndef ONLINE_JUDGE
    auto stop1 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop1 - start1);
    cerr << "Time : " << duration.count() / 1000000 << "seconds" << endl;
#endif

    return 0;
}
