#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<int> dp1;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        auto it = std::lower_bound(dp1.begin(), dp1.end(), x);
        if (it == dp1.end()) {
            dp1.push_back(x);
        }else {
            *it = x;
        }
    }
    std::cout << dp1.size() << std::endl;	
    return 0;
}  