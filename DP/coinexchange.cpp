#include<bits/stdc++.h>
// DONE
long long int count(int n, int coins[], int sum){
    long long int ans = 0;
    int dp[sum+1];
    for(int i=0;i<sum+1;i++) dp[i]=0;
    dp[0] = 1;
    // for(int i=0;i<n;i++) dp[coins[i]] =1 ;
    // for(int i=0;i<=sum;i++){
    //     bool check[sum+1];
    //     // for(int i=0;i<sum+1;i++) check[i]=false;
    //     for(int j=0;j<n;j++){
    //         if(i>coins[j]){
    //             dp[i] += dp[i-coins[j]];
    //         }
    //     }
    // }
    for(int i=0;i<n;i++){
        for(int j=coins[i];j<=sum;j++) dp[j] += dp[j-coins[i]];
    }
    return dp[sum];
}

int main(){
    int t; std::cin>>t;
    while(t--){
        int n; std::cin>>n;
        int coins[n];
        for(int i=0;i<n;i++) std::cin>>coins[i];
        int sum; std::cin>>sum;
        std::cout<<count(n,coins,sum)<<"\n";
    }
}