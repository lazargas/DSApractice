#include <bits/stdc++.h>
using namespace std;

// int solvedp(int i,int n,vector<int> &arr,vector<int> &dp){
//     if(i==n)return 0;
//     if(dp[i]!=-1)return dp[i];
//     int paycoin = 1 + solve(i+1,n,arr,dp);
//     int adjB = INT_MAX;
//     if(i>0 and arr[i-1]!=0){
//         --arr[i-1];
//         adjB = solve(i+1,n,arr,dp);
//     }
//     int adjF = INT_MAX;
//     if(i<n-1 and arr[i+1]!=0){
//         --arr[i+1];
//         adjF = solve(i+1,n,arr,dp);
//     }
//     dp[i] = min(paycoin,min(adjB,adjF));
//     return dp[i];
// }

int solvegreedy(int n,vector<int> arr){
    vector<int> copy;
    int mincoins=1;
    int lastel=-1;
    for(int i=0;i<n;i++){
      if(arr[i]==0){
        copy.push_back(arr[i]);
        lastel=i;
    }
      else{
         if(lastel==-1 or arr[lastel]==0){
            copy.push_back(arr[i]);
            lastel=i;
         }
      }
    }
    cout<<copy.size();
    for(int i=0;i<copy.size();i++){
       if(copy[i]==0){
         if(i>0 and copy[i-1]!=0){
             --copy[i-1];
             continue;
         }
         else if(i<copy.size()-1 and copy[i+1]!=0){
            --copy[i+1];
            continue;
         }
         else{
            mincoins++;
         }
       }
    }
    return mincoins;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
       int n;
       cin>>n;
       vector<int> arr;
       for(int i=0;i<n;i++){
           int temp;
           cin>>temp;
           arr.push_back(temp);
       }
       vector<int> dp(n,-1);
       int ans = solvegreedy(n,arr);
       cout<<ans<<endl;
    
    return 0;
}