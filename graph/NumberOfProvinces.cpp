#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

class Solution
{
public:
    void dfs(vector<vector<ll>> adj, vector<ll> &vis, ll v)
    {

        stack<ll> s;
        vis[v] = 1;
        s.push(v);
        while (!s.empty())
        {
            ll curr = s.top();
            s.pop();
            for (auto i = 0; i < adj[curr].size(); i++)
            {
                if (adj[curr][i] == 1 && vis[i] == -1)
                {
                    s.push(i);
                    vis[i] = 1;
                }
            }
        }
    }

    ll numberOfProvinces(vector<vector<ll>> adj, ll v)
    {
        vector<ll> vis(v, -1);
        ll ans = 0;
        for (int i = 0; i < v; i++)
        {
            if (vis[i] == -1)
            {
                ans++;
                dfs(adj, vis, i);
            }
        }
        return ans;
    }
};

void solve()
{
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    Solution ob;
    while (t--)
    {
        ll v, e;
        cin >> v;
        vector<vector<ll>> adj;
        forn(i, v)
        {
            vector<ll> temp;
            forn(j, v)
            {
                cin >> e;
                temp.push_back(e);
            }
            adj.push_back(temp);
        }

        cout << ob.numberOfProvinces(adj, v) << "\n";
    }

    return 0;
}
