#include<bits/stdc++.h>
#include<algorithm>
typedef long long ll;


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t; std::cin>>t;
    while(t--){
    int n; std::cin>>n;
    int a[n];
    for(int i=0;i<n;i++) std::cin>>a[i];
    std::sort(a,a+n);
    std::cout<<2*(a[n-1]+a[n-2]-a[0]-a[1])<<"\n";}
}