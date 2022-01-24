#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

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

// code starts here

/*
evaluates the floor of an element in passed vector

@return returns a pair containing index of floor of target and it's value, return {-1,-1} if floor does not exist
*/
pair<int, int> FloorOfAnElementInArray(vector<int> vec, int target)
{
    int start = 0, end = vec.size() - 1, mid = 0, flr = -1, index = -1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (vec[mid] < target)
        {
            flr = vec[mid];
            index = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return make_pair(index, flr);
}

int solve()
{
    vector<int> vec{1, 2, 3, 4, 5, 6, 7};
    auto ans = FloorOfAnElementInArray(vec, 7);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}

signed main()
{
    SaveTime();
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    solve();
    return 0;
}