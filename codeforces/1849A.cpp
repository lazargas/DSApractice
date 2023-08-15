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
    int a,b,c;
    cin>>a>>b>>c;
    if(a>b+c){
       int n = b+c;
       cout<<(2*n+1)<<endl;
    }
    else{
        int n = a;
        cout<<(2*n-1)<<endl;
    }
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
    
    // int n,k;
    // cin>>n>>k;
    // vector<pair<int,int>> ans;
    // for(int i=0;i<n;i++){
    //     int x;
    //     cin>>x;
    //     if(x%k==0)cout<<i+1<<" ";
    //     else{
    //         ans.push_back({x%k,i+1});
    //     }
    // }
    // sort(ans.begin(),ans.end(),cmp);
    // for(auto it:ans){
    //     cout<<it.second<<" ";
    // }
    // cout<<endl;
    }
    return 0;
}