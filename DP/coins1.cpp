#include<bits/stdc++.h>

class Solution{
    public:
    int coins1(int n, int x, int coins[]){
        int dp[x+1];
        for(int i=0;i<x+1;i++) dp[i]=0;
        dp[0]=1;
        for(int i=0;i<x+1;i++){
            for(int j=0;j<n;j++){
                if(i-coins[j]>=0){
                    dp[i] += dp[i-coins[j]];
                    dp[i] = dp[i]%(1000000007);
                }
            }
        }
        return (dp[x]%1000000007);
    }

    int coins2(int n, int x, int coins[]){
        int dp[x+1];
        for(int i=0;i<x+1;i++) dp[i]=0;
        dp[0]=1;
        for(int j=0;j<n;j++){
            for(int i=coins[j];i<x+1;i++){
                dp[i]  += dp[i-coins[j]];
                dp[i] = dp[i]%(1000000007);
            }
        }
        return (dp[x]%1000000007);
    }
};
int main(){
    int n, x;
    std::cin>>n>>x;
    int coins[n];
    for(int i=0;i<n;i++) std::cin>>coins[i];
    Solution obj;
    // std::cout<<obj.coins1(n,x,coins)<<"\n";
    // std::cout<<obj.coins2(n,x,coins)<<"\n";
}