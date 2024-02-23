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
    // Now we have n in order of decreasing time.
    

    // for(auto &i : vec){
    //     std::cout<<i.a1<<" ";
    //     std::cout<<i.b1<<" ";
    //     std::cout<<i.p<<" ";
    //     std::cout<<"\n";
    // }

    return 0;
}
