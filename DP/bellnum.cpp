#include<bits/stdc++.h>

int main(){
    // recursion for this is S(n+1,k) = k*S(n,k)[added to sets of every partion] + S(n,k-1)[Added as single element to existing partion]
    int t; std::cin>>t;
    while(t--){
        int n; std::cin>>n;
        long dp[n+1][n+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(j>i) dp[i][j] = 0;
                else if(j==i) dp[i][j] = 1;
                else if(i==0||j==0) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j]*j + dp[i-1][j-1];
            }
        }
        int ans=0;
        for(int i=0;i<=n;i++){
            ans += dp[n][i];
        }
        std::cout<<ans<<std::endl;
    }
}