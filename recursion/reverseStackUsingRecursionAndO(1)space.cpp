#include <bits/stdc++.h>
#include <chrono>
#include <ctime>

#define deb(x) cout << (#x) << " is " << (x) << endl
#define nline "\n"
#define read(x) int x; cin>>x
#define SaveTime() ios_base::sync_with_stdio(false);std::cin.tie(NULL)
#define setDecimalPrecision(Precision) fixed<<showpoint<<setprecision(Precision)
typedef long long int ll;

const int MOD = 1000000007;

using namespace std;

void printVect(vector<int> vi) {
    int size = vi.size();
    for (ll i = 0; i < size; ++i) {
        cout << vi[i] << " ";
    }
    cout << nline;
}

void insert_at_stackend(stack<int> &s, int x) {
    if (s.size() == 0) {
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();
    insert_at_stackend(s, x);
    s.push(temp);
    return;
}

void reverse_stack(stack<int> &st) {
    if (st.size() == 1) {
        return;
    }
    int temp = st.top();
    st.pop();
    reverse_stack(st);
    insert_at_stackend(st, temp);
    return;
}

int solve() {
    stack<int> my_stack;
    my_stack.push(1);
    my_stack.push(3);
    my_stack.push(2);
    reverse_stack(my_stack);
    while (!my_stack.empty()) {
        cout << my_stack.top() << " ";
        my_stack.pop();
    }
    return 0;
}

int main() {
    SaveTime();
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    auto start1 = std::chrono::high_resolution_clock::now();
#endif

    int T = 1;
    cin >> T;
    while (T--)
        solve();

    return 0;
}
