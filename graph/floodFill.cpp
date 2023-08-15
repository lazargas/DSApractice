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
    bool validIndex(int i, int j, vector<vector<ll>> &image, vector<vector<ll>> &vis,ll Color)
    {
        int n = image.size();
        int m = image[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m || image[i][j] != Color || vis[i][j] == 2)
            return false;
        else
            return true;
    }
    vector<vector<ll>> floodFill(vector<vector<ll>> &image, ll sr, ll sc, ll newColor)
    {
         vector<vector<ll>> vis(image.size(),vector<ll>(image[0].size(),-1));
        stack<pair<ll,ll>> s;
        vis[sr][sc]=2;
        ll color = image[sr][sc];
        image[sr][sc]=newColor;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, 1, 0, -1}; 
        s.push({sr,sc});
        while(!s.empty()){
           pair<ll,ll> curr = s.top();
           s.pop();
           forn(i,4){
            int r = curr.first + drow[i];
            int c = curr.second + dcol[i];
            
            if(validIndex(r,c,image,vis,color)){
                s.push({r,c});
                vis[r][c]=2;
                image[r][c]=newColor;
            }


           }
        }
        return image;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> image(n, vector<ll>(m, -1));
    forn(i, n)
    {
         forn(j, m)
         {
             ll temp;
             cin >> temp;
             image[i][j] = temp;
         }
    }
    ll sr, sc, newColor;
    cin >> sr >> sc >> newColor;
    Solution ob;
    vector<vector<ll>> ans = ob.floodFill(image,sr,sc,newColor);
    forn(i,n){
       cout<<"\n"; 
       forn(j,m){
          cout<<ans[i][j]<<" ";
       }
    }

    return 0;
}
