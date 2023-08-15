class Solution {
public:
   
   void solve(vector<vector<int>> &ans,vector<int> &temp,int index,vector<int> nums){
       ans.push_back(temp);
       for(int i=index;i<nums.size();i++){
           
           if(nums[i]==nums[i-1] && i>index )continue;

           temp.push_back(nums[i]);
           solve(ans,temp,i+1,nums);
           temp.pop_back();
       }
   }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp={};
        int index=0;
        sort(nums.begin(),nums.end());
        solve(ans,temp,index,nums);
        
        return ans;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ll v, e;
  cin >> v >> e;
  vector<ll> adj[v];
  forn(i, e)
  {
    ll x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  Solution ob;
  bool ans = ob.isCycle(v, adj);
  cout << ans << "\n";
  return 0;
}
