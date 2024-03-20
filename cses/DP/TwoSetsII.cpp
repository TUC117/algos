#include<bits/stdc++.h>
typedef long long ll;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin>>n;
    if((n*(n+1)/2)%2 == 1){
        std::cout<<0<<"\n";
        return 0;
    }
    int target = (n)*(n+1)/4;
    // dp[i][j] = dp[i-1][j] + dp[i-1][j-i];
    std::vector<std::vector<int>> dp(n+1,std::vector<int>(target+1,0));
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){    
        for(int j=0;j<=target;j++){
            dp[i][j] = dp[i-1][j];
            if(j-i>=0) dp[i][j] += dp[i-1][j-i];
            dp[i][j] %= 1000000007;
        }
    }
    std::cout<<dp[n-1][target]<<"\n";
}