#include<bits/stdc++.h>

// USING DP O(n^2)
int main(){
    int t; std::cin>>t;
    while(t--){
    int n; std::cin>>n;
    unsigned long int dp[n+1];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=0;
        for(int j=0;j<i;j++){
            dp[i] += dp[j]*dp[i-j-1];
        }
    }
    std::cout<<dp[n]<<std::endl;}
}