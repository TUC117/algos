#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n, 0));
    vector<int> dp((1<<n), INT_MAX);
    dp[0] = 0;
    for(int i=0; i<n; i++) {
        // cin >> m[i][i];
        for(int j=0; j<n; j++) {
            cin >> m[i][j];
        }
    }
    vector<int> sum(1<<n, 0);

    for(int mask=0; mask<(1<<n); mask++) {
        for(int i=0; i<n; i++) {
            if(mask&(1<<i)) {
                for(int j=i+1; j<n; j++) {
                    if(!(mask&(1<<j))) {
                        sum[mask] += m[i][j];
                    }
                }
            }
        }
    }
    for(int i=0;i< 1<<n;i++){
        // cout << i << " "<< sum[i]<<endl;
    }

    // for(int mask=0; mask<(1<<n); mask++) {
    //     for(int i=0; i<n; i++) {
    //         if(!(mask&(1<<i))) {
    //             int newMask = mask|(1<<i);
    //             int mem = m[i+1][i+1];
    //             for(int j=0; j<i; j++) {
    //                 if(mask&(1<<j)) {
    //                     mem += m[j+1][i+1];
    //                 }
    //             }
    //             dp[newMask] = min(dp[newMask], max(dp[mask]+sum[mask]-sum[mask&(mask^(1<<i))]+mem, dp[mask]+mem));
    //         }
    //     }
    // }
    // cout << dp[(1<<n)-1] << endl;
    return 0;
}
