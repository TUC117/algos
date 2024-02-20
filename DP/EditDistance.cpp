#include<bits/stdc++.h>
using namespace std;
int main(){
    string a, b;
    cin>>a>>b;

    int n = a.length(), m = b.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    for(int i=0;i<m+1;i++){
        dp[0][i] = i;
    }
    for(int i=0;i<n+1;i++){
        dp[i][0] = i;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            char x = a[i-1], y = b[j-1];
            if(x==y){
                dp[i][j] = dp[i-1][j-1];// If Last letter same means do nothing
            }
            else{
                dp[i][j] = dp[i-1][j-1]+1; // Delete else both
            }
            dp[i][j] = min(dp[i][j], dp[i-1][j]+1); // case where we ignore one
            dp[i][j] = min(dp[i][j], dp[i][j-1]+1); 
        }
    }
    cout<<dp[n][m]<<endl;
}