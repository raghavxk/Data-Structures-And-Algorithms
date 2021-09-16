#include <bits/stdc++.h>

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

vector<int> graph[10001];
bool visited[10001];
int dist[10001];
vector<int> primes;

bool isPrime(int num)
{
    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

bool isValid(int a, int b)
{
    int count = 0;
    while (a > 0 and b > 0)
    {
        if (a % 10 != b % 10)
        {
            count++;
        }
        a = a / 10;
        b = b / 10;
    }
    if (count == 1)
        return true;
    else
        return false;
}

void BuildGraph()
{
    for (int i = 1000; i <= 9999; ++i)
    {
        if (isPrime(i))
        {
            primes.push_back(i);
        }
    }
    for (int i = 0; i < primes.size(); ++i)
    {
        for (int j = i + 1; j < primes.size(); ++j)
        {
            if (isValid(primes[i], primes[j]))
            {
                graph[primes[i]].push_back(primes[j]);
                graph[primes[j]].push_back(primes[i]);
            }
        }
    }
}

void BFS(int source)
{
    queue<int> q;
    visited[source] = true;
    dist[source] = 0;
    q.push(source);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int child : graph[curr])
        {
            if (visited[child] == false)
            {
                q.push(child);
                visited[child] = true;
                dist[child] = dist[curr] + 1;
            }
        }
    }
}

void solve()
{
    int tc;
    cin >> tc;
    BuildGraph();
    while (tc--)
    {
        int a, b;
        cin >> a >> b;
        for (int i = 1000; i <= 9999; ++i)
        {
            dist[i] = -1;
            visited[i] = false;
        }

        BFS(a);

        if (dist[b] == -1)
            cout << "Impossible" << endl;
        else
            cout << dist[b] << endl;
    }
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
