#include <bits/stdc++.h>
#include <ctime>
using namespace std;
#define MAXN 202020

vector<vector<int>> adj(MAXN);
vector<int>subtree_size(MAXN);

int calc (int node) {
   if (adj[node].size() == 0) {
      return 1;
   } else {
       for (int i = 0; i < adj[node].size(); i++) {
          subtree_size[node] += calc(adj[node][i]);
       }
   }
   return subtree_size[node] + 1;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    clock_t tStart = clock();
#endif
  
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
      int boss;
      cin >> boss;
      adj[boss].push_back(i);
  }
  calc(1);
  for (int i = 1; i <= n; i++) {
      cout << subtree_size[i] << " ";
  }
  #ifndef ONLINE_JUDGE
    
    cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
  #endif
}