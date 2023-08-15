#include <bits/stdc++.h>
using namespace std;

 int solve(int i,string s,string t,vector<char> temp,int n){
        if(i>n-1){
            string tempt(temp.begin(),temp.end());
            if(tempt==t)return 1;
            else return 0;
        }

        temp.push_back(s[i]);
        int take = solve(i+1,s,t,temp,n);
        temp.pop_back();
        int nottake = solve(i+1,s,t,temp,n);
        
        int ans = take+nottake;
        return ans;

    }

int main(){
     #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s,t;
    cin>>s>>t;
    string temp;
    cout<<solve(0,s,t,temp,s.length());
    return 0;
}