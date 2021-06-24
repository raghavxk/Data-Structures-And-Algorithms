// recursive linear search

#include <bits/stdc++.h>
#include <chrono>
#include <ctime>

#define deb(x) cout << (#x) << " is " << (x) << endl
#define nline "\n"
#define read(x) int x; cin>>x
#define fastio() ios_base::sync_with_stdio(false);std::cin.tie(NULL)
typedef long long int ll;

using namespace std;

bool searchArr(vector<int> v, int key) {
    if(v.size()==0)
        return false;
    if(v[v.size()-1]==key)
        return true;
    v.pop_back();
    return searchArr(v,key);

}

int solve() {
    vector<int> v = {1, 6, 7, 8, 9, 9, 3};
    cout << searchArr(v, -3);
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
