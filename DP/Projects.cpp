#include<bits/stdc++.h>
#include<algorithm>
typedef long long ll;
struct object{
    int a1;
    int b1;
    int p;
};

// Comparator function for std::upper_bound
bool compare(const object &a, const object &b) {
    return a.b1 < b.b1;
}
int getk(std::vector<object>& vec, int i) {
    int left = i;
    int target = vec[i].b1;
    int right = vec.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // If target greater, ignore left half
        if (vec[mid].a1 <= target) {
            left = mid + 1;
        }
        // If target is smaller or equal, ignore right half
        else {
            right = mid - 1;
        }
    }

    // If we reach here, then left is the index of the a1 element greater than target
    if (left < vec.size() && vec[left].a1 > target) {
        return left;
    }

    // If no element is greater than target
    return -1;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin>>n;
    std::vector<object> vec;
    for(int i=0;i<n;i++){
        object temp;
        std::cin>>temp.a1;
        std::cin>>temp.b1;
        std::cin>>temp.p;

        auto it = std::upper_bound(vec.begin(), vec.end(), temp, compare);
        vec.insert(it, temp);
    }
    
    std::vector<int> dp(n+1,INT_MIN);
    for(int i=1;i<n+1;i++) dp[i] = vec[i-1].p;
    
    for(int i=n-1;i>=0;i--){
        int k = getk(vec, i);
        dp[i] = std::max(dp[i+1],dp[i]);
        if(k!=-1 && i+k<n) dp[i] = std::max(dp[i+1], dp[i+1+k]+vec[i].p);
    }
    std::cout<<dp[0]<<"\n";
    

    return 0;
}
