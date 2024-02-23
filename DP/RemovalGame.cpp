#include<bits/stdc++.h>
typedef long long ll;
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin>>n;
    std::vector<int> a(n);
    ll x=0;

    std::vector<std::vector<ll>> dp(n,std::vector<ll>(n));

    // dp[i][j] represents first-second 
    // dp[i][j] = a[i] - dp[i+1][j]
    // dp[i][j] = -dp[i][j-1] + a[j]

    for(int& i:a){
        std::cin>>i;
        x += i;
    }
    // dp[0][0] = 1;
    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            if(i==j) dp[i][j] = a[i];
            else dp[i][j] = std::max(a[i]-dp[i+1][j], -dp[i][j-1]+a[j]);
        }
    }   

    std::cout<<(x+dp[0][n-1])/2<<"\n";

}