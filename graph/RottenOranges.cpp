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
    bool validIndex(int i, int j, vector<vector<ll>> &adj, vector<vector<ll>> &vis)
    {
        int n = adj.size();
        int m = adj[0].size();
        if (i < 0 || i >= n || j < 0 || j>= m || adj[i][j] == 0 || adj[i][j] == 2 || vis[i][j] == 2)
            return false;
        else
            return true;
    }

    ll bfs(queue<vector<ll>> &q,vector<vector<ll>> &vis, vector<vector<ll>> &adj,ll cntf)
    {
        ll cnt = 0;
        ll mxt = -1;

        while (!q.empty())
        {
            vector<ll> curr = q.front();
            mxt = max(curr[2], mxt);
            q.pop();

            if (validIndex(curr[0] + 1, curr[1], adj, vis))
            {

                q.push({curr[0] + 1, curr[1], curr[2] + 1});
                vis[curr[0] + 1][curr[1]] = 2;
                cnt++;
            }
            if (validIndex(curr[0] - 1, curr[1], adj, vis))
            {

                q.push({curr[0] - 1, curr[1], curr[2] + 1});
                vis[curr[0] - 1][curr[1]] = 2;
                cnt++;
            }
            if (validIndex(curr[0], curr[1] + 1, adj, vis))
            {
                q.push({curr[0], curr[1] + 1, curr[2] + 1});
                vis[curr[0]][curr[1] + 1] = 2;
                cnt++;
            }
            if (validIndex(curr[0], curr[1] - 1, adj, vis))
            {
                q.push({curr[0], curr[1] - 1, curr[2] + 1});
                vis[curr[0]][curr[1] - 1] = 2;
                cnt++;
            }
        }
        if(cnt!=cntf)return -1;
        return mxt;
    }

    ll orangesRotting(vector<vector<ll>> &adj)
    {
        queue<vector<ll>> q;
        ll mxt = -1;
        ll n = adj.size();
        ll m = adj[0].size();
        ll cntf = 0;
        vector<vector<ll>> vis(n, vector<ll>(m, -1));
        forn(i, n)
        {
            forn(j, m)
            {
                if (adj[i][j] == 1)
                {

                    cntf++;
                }
            }
        }
        forn(i, n)
        {
            forn(j, m)
            {
                if (adj[i][j] == 2)
                {
                    q.push({i, j, 0});
                    vis[i][j]=2;
                }
            }
        }
        ll t = bfs(q,vis,adj,cntf);
        return t;
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
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj;
    forn(i, n)
    {
        forn(j, m)
        {
            ll temp;
            cin >> temp;
            adj[i][j] = temp;
        }
    }
    Solution ob;
    cout << ob.orangesRotting(adj) << " ";
    cout<<"akarsh"<<endl;
    return 0;
}
