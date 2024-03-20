#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;

int find_mex(std::vector<int>& arr,int n) {
    // std::sort(arr.begin(), arr.end());
    int mex = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] >= mex) {
            mex++;
        }
    }
    return mex;
}


void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n);
    for(auto&i:a) cin>>i;

    int mex = find_mex(a,n);
    int k = 0;
    int tempmex=0;
    for(int i=0;i<n;i++){
        tempmex = find_mex(a,i+1);
        
        if(tempmex==mex){   
            tempmex = 0;
            k++;
        }
    }
    if(k>=2) cout<<k<<endl;
    else cout<<-1<<endl;
       
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t; std::cin>>t;
    while(t--){
        solve();
    }
}