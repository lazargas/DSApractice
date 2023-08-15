#include<bits/stdc++.h>
using namespace std;
#define SZ 200005
 
int n, m, x, y; 
vector<int> adj[SZ];
 
pair<int,int> bfs(int src)
{
	int d = 0;
	queue<pair<int,int> > q;
	q.push({src, 0});
	vector<bool> vis(SZ, false);
	pair<int,int>  u;
 
	while(!q.empty()) {
		u = q.front();
		vis[u.first] = true;
		q.pop();
		for(int v: adj[u.first])
			if(!vis[v])
			q.push({v, u.second + 1});
	}
	return u;
}
 
int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
#endif
	cin >> n;
	for(int i = 0; i < n-1; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	vector<int> ans;
	for(int i=1;i<=n;i++){
	pair<int,int>  end1 = bfs(i);
	pair<int,int>  end2 = bfs(end1.first);
	ans.push_back(end2.second);
  }
  for(auto it:ans){
	cout<<it<<" ";
  }
}