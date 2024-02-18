#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int longest_increasing_subsequence(std::vector<int>& nums) {
    std::vector<int> tails(nums.size(), 0);
    int size = 0;
    for (int x : nums) {
        int i = 0, j = size;
        while (i != j) {
            int m = (i + j) / 2;
            if (tails[m] < x)
                i = m + 1;
            else
                j = m;
        }
        tails[i] = x;
        if (i == size) ++size;
    }
    return size;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i:nums){
        cin>>i;
    }
    cout<<longest_increasing_subsequence(nums)<<endl;
}