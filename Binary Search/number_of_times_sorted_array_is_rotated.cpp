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

// algorithm works only for distinct array integers
int NumberOfTimesArrayIsRotated(vector<int> vec)
{
    int low = 0, high = vec.size() - 1;
    // check for if array is already sorted
    if (vec[low] < vec[high])
    {
        return 0;
    }
    int mid = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        int index_of_next = (mid + 1) % vec.size();
        int index_of_prev = (mid - 1 + vec.size()) % vec.size();
        if (vec[mid] <= vec[index_of_next] and vec[mid] <= vec[index_of_prev])
        {
            return mid;
        }
        else if (vec[mid] <= vec[high])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return 0;
}

int solve()
{
    vector<int> vec{7, 7, 7, 7, 7};
    cout << NumberOfTimesArrayIsRotated(vec) << endl;
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