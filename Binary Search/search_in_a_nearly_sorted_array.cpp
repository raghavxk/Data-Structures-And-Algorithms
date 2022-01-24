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
/*
Question: nearly sorted array means that in a sorted array elements have been randomly displaced at any of the positions i.e
i-1, i , i+1
*/

int SearchInANearlySortedArray(vector<int> vec, int target)
{
    int start = 0, end = vec.size() - 1, mid = 0;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (vec[mid] == target)
        {
            return mid;
        }
        else if (mid - 1 >= start and vec[mid - 1] == target)
        {
            return mid - 1;
        }
        else if (mid + 1 <= end and vec[mid + 1] == target)
        {
            return mid + 1;
        }
        else if (target < vec[mid])
        {
            end = mid - 2;
        }
        else
        {
            start = mid + 2;
        }
    }
    return -1;
}

int solve()
{
    vector<int> vec{5, 10, 30, 20, 40};
    cout << SearchInANearlySortedArray(vec, 40) << endl;
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