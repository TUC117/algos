#include<bits/stdc++.h>

int main(){
    int t; std::cin>>t;
    while(t--){
    int n; std::cin>>n;
    int dp[n];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    std::cout<<dp[n-1]+dp[n-2]<<std::endl;}
}