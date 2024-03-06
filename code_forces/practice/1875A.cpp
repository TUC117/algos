#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define fi(i,a,b) for(ll i(a);i<b;i++)
#define fd(i,a,b) for(ll i(a);i>=b;i--)

void solve(){
    ll a,b,n;
    cin>>a>>b>>n;
    vector<ll> num(n);
    ll sum = 0;
    for(auto&i:num) {
        cin>>i;
        ll x = min(1+i,a);
        sum += x-1;
    }
    ll ans = 0;
    ans += sum;
    ans += b;
    cout<<ans<<"\n";

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
}