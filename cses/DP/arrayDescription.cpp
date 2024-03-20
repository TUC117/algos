#include<bits/stdc++.h>
#define MODA 1000000007

int main(){
    // Taking the inputs
    int n, m;
    std::cin>>n>>m;
    std::vector<int> a(n);
    for(auto &i:a) std::cin>>i;

    // Constructing the DP
    std::vector<std::vector<int>> dp(n, std::vector<int>(m+2,0));

    // Base case if a[0] = 0 or a[0] = k dp[0][j] = 1;
    
    for(int i=1;i<m+1;i++){
        if(a[0]==0 || a[0]==i)
            dp[1][i] = 1;
    }
    for(int i=2;i<n;i++){
        for(int j=1;j<m+1;j++){
            if(a[i-1]==0 || a[i-1]==j){
                dp[i][j] = ((dp[i-1][j] + dp[i-1][j-1]) % MODA + dp[i-1][j+1]) % MODA;
            }
        }
    }
    int sum = 0;
    for(int i=0;i<m+1;i++)
        sum = (sum + dp[n-1][i]) % MODA;

    std::cout<<sum<<"\n";
}
