#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    int a= max(m,n)/min(m,n);
    

    int dp[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            dp[i][j]=INT_MAX;
        }
    }
    dp[0][0]=0;
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = 0;
    }
    for(int i=2;i<=n;i++){
        dp[i][1] = i-1;
    }
    for(int i=2;i<=m;i++){
        dp[1][i] = i-1;
    }
    // for(int i=min(m,n);i<m+1;i++){
    //     dp[0][i] = i-min(m,n)+1;
    // }
    // for(int i=min(m,n);i<n+1;i++){
    //     dp[i][0] = i-min(m,n)+1;
    // }
    dp[1][1]=0;
    for(int i=2;i<n+1;i++){
        for(int j=2;j<m+1;j++){
            if(i==j) dp[i][j] = 0;
            // else{
                
                for(int k=1;k<=i;k++){
                    dp[i][j] = min(dp[i-k][j]+dp[k][j]+1, dp[i][j]);
                }
                for(int k=1;k<=j;k++){
                    dp[i][j] = min(dp[i][j-k]+dp[i][k]+1, dp[i][j]);
                }
            // }
        }
    }
    // for(int i=0;i<n+1;i++){
    //     for(int j=0;j<m+1;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[n][m]<<endl;
}
