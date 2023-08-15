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
	vector<vector<ll>> adj(n+1,vector<ll>(n+1,0));
	// forn(i,n){
	// 	forn(j,n){
	// 		cout<<adj[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	forn(i,m){
		ll u,v;
		cin>>u>>v;

		adj[u-1][v-1]=1;
		adj[v-1][u-1]=1;



	}

	forn(i,n){
		forn(j,n){
			cout<<adj[i][j]<<" ";
		}
		cout<<"\n";
	}





	// unordered_map<ll, list<ll>> adj;
	// adj[0].push_back(1);
	// adj[0].push_back(2);
	// adj[0].push_back(3);
	// adj[2].push_back(0);
	// adj[2].push_back(3);
	// adj[2].push_back(4);
	// adj[3].push_back(0);
	// adj[3].push_back(2);
	// for (auto y : adj)
	// {
	// 	cout << y.first << " ";
	// 	for (auto x : y.second)
	// 	{
	// 		cout << x << " ";
	// 	}
	// 	cout << "\n";
	// }
	vector<ll> vis(n, -1);
	stack<ll> s;
	s.push(0);
	vis[0] = 1;
	while (!s.empty())
	{
		ll curr = s.top();
		s.pop();
		cout<<curr<<" ";
		for(auto i = 0; i<adj[curr].size();i++){
			
			if(adj[curr][i]==1&&vis[i]==-1)
			{
				s.push(i);
				vis[i]=1;
			}
			
		
		}
	}

	return 0;
}
