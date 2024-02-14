#include<bits/stdc++.h>
// DONE
class Solution{
public:
    long long int sum(int n){
        long long int dp[n+1];
        for(int i=0;i<n+1;i++){dp[i]=0;}
        dp[0] = 1;
        for(int i=0;i<n+1;i++){
            for(int j=1;j<7;j++){
                if(i-j>=0){
                    dp[i] += dp[i-j];
                    dp[i] = dp[i]%(1000000007);
                }
            }
        }
        return dp[n]%(1000000007);
    }
};
int main(){
    int n; std::cin>>n;
    Solution ans;
    std::cout<<ans.sum(n)<<"\n";
}