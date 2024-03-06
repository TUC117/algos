#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define vec(x) vector<x> 
#define fi(i,a,b) for(ll i(a);i<b;i++)
#define fd(i,a,b) for(ll i(a);i>=b;i--)
#define juuui()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));

void solve(){
    ll n,k;
    cin>>n>>k;
    vec(ll) a(n);
    for(auto&i:a) cin>>i;
    sort(all(a));
    ll left = 0, right = 0, ans = INT_MAX;
    fi(i,0,n-1){
        if(a[i+1]-a[i] > k){
            ll temp = left+n-i-1;
            ans = min(ans,temp);
            left = i+1;
        }
    }
    ans = min(ans,left);
    if(ans==INT_MAX)cout<<0<<"\n";
    else cout<<ans<<"\n";
}
int main(){
    juuui();
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
}