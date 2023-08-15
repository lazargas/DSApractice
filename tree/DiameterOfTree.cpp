#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(int i,vector<vector<ll>> adj,vector<int> &vis,int n,vector<ll> &dp){
    
    if(dp[i]!=-1)return dp[i];
    
    vis[i]=1;
    

    ll res = -1;
    for(auto it:adj[i]){
        if(vis[it]==0){
            res = max(res,solve(it,adj,vis,n,dp));
        }
    }

    return dp[i]=1+res;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
  ll n;
  cin>>n;
  vector<vector<ll>> adj(n+1);
  for(int i=1;i<n;i++){
     int u,v;
     cin>>u>>v;
     adj[u].push_back(v);
     adj[v].push_back(u);
  }
  
  
  
  ll res = INT_MIN;
  ll maxim = INT_MIN;
  for(int i=1;i<=n;i++){
     vector<ll> dp(n+1,-1);
     vector<int> vis(n+1,0);
     res = max(res,solve(i,adj,vis,n,dp));
//      for(auto it:dp){
//       maxim = max(maxim,it);
//   }
//   cout<<endl;
  }

  cout<<res<<endl;
  
  
  
  return 0;
}