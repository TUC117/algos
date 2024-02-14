#include<bits/stdc++.h>
// DOING
class Solution{
    public:
    int griddp(int n, char grid[][1000]){
        int dp[n][n];
        for(int i=0;i<n;i++){
            if(i==n-1){
                for(int j=n-1;j>=0;j--){
                    if(grid[n-1][j]=='.') dp[n-1][j] = 1;
                    else{
                        for(int k=j;k>=0;k--){
                            dp[n-1][k] = 0;
                        }
                        break;
                    }
                }
            }
            else{
                for(int j=0;j<n;j++){
                    dp[i][j]=0;
                }
            }
        }
        // if(dp[])
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         std::cout<<dp[i][j]<<" ";
        //     }
        //     std::cout<<"\n";
        // }    
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]=='*') dp[i][j] = 0;
                else{
                    if(j!=n-1){
                        dp[i][j] = dp[i][j+1]+dp[i+1][j];
                        dp[i][j] = dp[i][j]%(1000000007);
                    }
                    else{
                        dp[i][j] = dp[i+1][j]%(1000000007);
                    }
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         std::cout<<dp[i][j]<<" ";
        //     }
        //     std::cout<<"\n";
        // }   
        return dp[0][0]%(1000000007);
        return -1;
    }
};
int main(){
    int n; std::cin>>n;
    char grid[1000][1000];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            std::cin>>grid[i][j];
        }
    }
    Solution ob;
    std::cout<<ob.griddp(n, grid)<<"\n";

}