#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	void dfs(vector<int> adj[],vector<int> &vis,int i,vector<int> &ans){
	    vis[i]=1;
	    ans.push_back(i);
	    
	    for(auto j:adj[i]){
	        if(vis[j]==-1){
	            dfs(adj,vis,j,ans);
	           
	        }
	    }
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
        vector<int> vis(n + 1, -1);
        vector<int> ans;
        for(int i=0;i<n;i++){
            dfs(adj,vis,i,ans);
        }
        
        
        return ans;
	}
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, e;
    cin >> n >> e;
    int u, v;
    vector<int> adj[n];
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    Solution ob;
    vector<int> ans = ob.topoSort(n,adj);
    for (auto i = ans.begin(); i <= ans.end(); i++)
    {
        cout << *i << " ";
    }
    return 0;
}