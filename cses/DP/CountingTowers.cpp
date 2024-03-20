#include<iostream>
using namespace std;

int main(){
    // int moda = 1000000007;
    int t;
    cin>>t;
    while(t--){
        int height; cin>>height;
        long long int dp[height+1][2];
        dp[1][0] = 1;
        dp[1][1] = 1;
        for(int i=2;i<=height;i++) {
            dp[i][0] = (dp[i-1][0]*4 + dp[i-1][1]*1)%1000000007;
            dp[i][1] = (dp[i-1][0]*1 + dp[i-1][1]*2)%1000000007;
        }
        cout<<(dp[height][0]+dp[height][1])%1000000007<<endl;
    }
}