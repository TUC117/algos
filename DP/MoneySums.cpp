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
    int dp[x+1];
    bool vdp[x+1];
    cout<<x<<endl;
    for(int i=0;i<x+1;i++) dp[i]=i;
    for(int i=0;i<x+1;i++) vdp[i]=false;
    dp[0]=1;
        for(int i=0;i<x+1;i++){
            for(int j=0;j<n;j++){
                if(dp[i]-a[j]==0 ){
                    vdp[i] = 1;
                    // dp[i] = dp[i]%(1000000007);
                }
                else{
                    dp[i] -= a[j];
                }
            }
        }
    for(int i=1;i<x+1;i++){
        // if(dp[i]!=0) cout<<i<<" ";
        cout<<vdp[i]<<" ";
    }
    cout<<endl;
}