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

void dfs(int row,int col,vector<vector<char>> arr,vector<vector<int>> &vis,int delrow[],int delcol[],int &count,char character){
   vis[row][col]=1;
   count++;
   if(count==3)return;
   
   for(int i=0;i<8;i++){
	 int nrow = row+delrow[i];
	 int ncol = col+delcol[i];

	 if(nrow>=0 and nrow<3 and ncol>=0 and ncol<3 and vis[nrow][ncol]==0 and arr[nrow][ncol]==character){
		dfs(nrow,ncol,arr,vis,delrow,delcol,count,character);
	 }
   }
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int t;
	cin>>t;
	while(t--){
		vector<vector<char>> arr(3,vector<char>(3,0));
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				char temp;
				cin>>temp;
				arr[i][j]=temp;
			}
		}
		vector<vector<int>> vis(3,vector<int>(3,0));
		int delrow[] = {-1,-1,0,1,1,1,0,-1};
		int delcol[] = {0,1,1,1,0,-1,-1,-1};
        int count = 0;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(vis[i][j]==0){
					count=0;
					dfs(i,j,arr,vis,delrow,delcol,count,arr[i][j]);
					if(count==3)
					{cout<<arr[i][j]<<'\n';
					break;
					}
					else if(count==3 and arr[i][j]=='.')
					{cout<<"DRAW"<<'\n';
					break;
					}
				}
			}
		}
		cout<<"asda"<<endl;
	}
	return 0;
}
