#include<bits/stdc++.h>
// DONE
class Solution{
    public:
    int getmaxdigit(int n){
        int maxdigit=n%10;
        n = n/10;
        while(n){
            if(n%10 > maxdigit) maxdigit = n%10;
            n = n/10;
        }
        return maxdigit;
    }
    int remove(int n){
        int ans = 0;
        while(n){
            int max_digit = getmaxdigit(n);
            n -= max_digit;
            ans++;
        }
        return ans;
    }
    int removedp(int n){
        int dp[n+1];
        for(int i=0;i<=n;i++) dp[i] = 0;
        dp[0]=1;
        // while(n){
        //     int max_digit = getmaxdigit(n);
        //     dp[n] += dp[n-max_digit];
        //     n -= max_digit;
        // }
        for(int i=1;i<n+1;i++){
            int max_digit = getmaxdigit(i);
            
            dp[i] += dp[i-max_digit]+1;
            // std::cout<<dp[i]<<"\n";
        }
        return dp[n]-1;
    }
};
int main(){
    int n;
    std::cin>>n;
    Solution obj;
    // std::cout<<obj.remove(n)<<"\n";
    std::cout<<obj.removedp(n)<<"\n";
}