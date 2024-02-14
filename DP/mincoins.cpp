#include<bits/stdc++.h>
// DONE
class Solution{
    public:
    int mincoins(int c[], int x, int n){
        int dp[x+1];
        for(int i=0;i<=x;i++) dp[i]=INT_MAX-1;
        dp[0] = 0;
        for(int i=0;i<x+1;i++){
            for(int j=0;j<n;j++){
                if(i-c[j]>=0){
                    dp[i] = std::min(dp[i], (dp[i-c[j]]+1));
                }
            }
        }
        if(dp[x]==2147483646) return -1;
        return dp[x] ;
    }
};
int main()
{
    int n, x;
    std::cin>>n>>x;
    int c[n];
    for(int i=0;i<n;i++) std::cin>>c[i];
    Solution ans;
    std::cout<<ans.mincoins(c,x,n)<<"\n";
}