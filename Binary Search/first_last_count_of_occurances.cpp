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

// Code starts here !

int FirstOccurance(vector<int> vec, int target)
{
    int low = 0, high = vec.size() - 1, mid = 0;
    int res = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (vec[mid] == target)
        {
            res = mid;
            high = mid - 1;
        }
        else if (vec[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}

int LastOccurance(vector<int> vec, int target)
{
    int low = 0, high = vec.size() - 1, mid = 0;
    int res = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (vec[mid] == target)
        {
            res = mid;
            low = mid + 1;
        }
        else if (vec[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}

int CountNumberOfOccurances(vector<int> vec, int target)
{
    bool found = binary_search(vec.begin(), vec.end(), target);
    if (found)
    {
        return LastOccurance(vec, target) - FirstOccurance(vec, target) + 1;
    }
    return -1;
}

int solve()
{
    vector<int> vec{1, 2, 3, 4, 4, 4, 4, 4, 5, 6};
    cout << LastOccurance(vec, 4) << endl;
    cout << FirstOccurance(vec, 4) << endl;
    cout << CountNumberOfOccurances(vec, 9) << endl;
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