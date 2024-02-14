#include<bits/stdc++.h>
// NOT DONE
class Solution{
    public:
    int knapSack(int W, int wt[], int val[], int n){
        int dp[W+1];
        int dpw[W+1];
        for(int i=0;i<=W;i++) {
            dp[i]=0;
            dpw[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=wt[i];j<=W;j++){
                if(dpw[j]>=0){
                dp[j] += val[i];
                dpw[j] -= wt[i];
            }
            }
        }
        int max = 0;
        for(int i=0;i<=W;i++){
            if(dp[i]>max) max = dp[i];
        }
        return max;
    }
};

int main(){
    int t; std::cin >> t;
    while(t--){
        int n, w;
        std::cin >> n >> w;
        int val[n];
        int weight[n];
        for(int i=0;i<n;i++) std::cin>>val[i];
        for(int i=0;i<n;i++) std::cin>>weight[i];
        Solution ans;
        std::cout<<ans.knapSack(w, weight, val, n)<<"\n";
    }
}