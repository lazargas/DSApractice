#include <bits/stdc++.h>
using namespace std;

struct Compare {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        
        if(a.first!=b.first){
            return a.first<b.first;
        }
        else{
            return a.second>b.second;
        }
    }
};

bool cmp(pair<int,int> a, pair<int,int> b) {
        
        if(a.first!=b.first){
            return a.first>b.first;
        }
        else{
            return a.second<b.second;
        }
    }


void solve(){
    int n;
    int k;
    cin>>n>>k;
    vector<int> monsters(n);
    for(int i=0;i<n;i++){
        cin>>monsters[i];
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
    for(int i=0;i<n;i++){
        pq.push({monsters[i],i});
    }
    vector<int> ans;
    while(!pq.empty()){
        pair<int,int> curr = pq.top();
        pq.pop();
        curr.first = curr.first - k;
        if(curr.first<=0){
            ans.push_back(curr.second+1);
        }
        else{
            pq.push({curr.first,curr.second});
        }
    }
    
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return;
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin>>t;
    while(t--){
    solve();
    
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> ans;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x%k==0)cout<<i+1<<" ";
        else{
            ans.push_back({x%k,i+1});
        }
    }
    sort(ans.begin(),ans.end(),cmp);
    for(auto it:ans){
        cout<<it.second<<" ";
    }
    cout<<endl;
    }
    return 0;
}