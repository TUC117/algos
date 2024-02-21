#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    int x=0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        x += a[i];
    }
    // int dp[n+1][x+1];
    

    bool dp[n+1][x+1];
    dp[0][0] = 1;
    for( int i=1;i<=x;i++) {dp[0][i] = 0;
    // maxprice[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            dp[i][j] = 0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            if(j-a[i-1] >=0) {
                dp[i][j] |= dp[i-1][j-a[i-1]];
            }
            dp[i][j] |= dp[i-1][j];
        }
    }
    int num = 0;
    for(int i=1;i<x+1;i++){
        if(dp[n][i]) num++;
    }
    cout<<num<<endl;
    for(int i=1;i<x+1;i++){
        if(dp[n][i]) cout<<i<<" ";
    }
    cout<<endl;
    
    
}