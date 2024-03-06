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
    int dx[4] = {-1,1,-1,1}, dy[4] = {-1, -1, 1, 1};
    ll a,b;
    cin>>a>>b;
    ll xk, yk; cin>>xk>>yk;
    ll xq, yq; cin>>xq>>yq;
    ll ans = 0;
    set<pair<ll,ll>> st1, st2;
    fi(i,0,4){
        st1.insert({xk+dx[i]*a, yk+dy[i]*b});
        st1.insert({xk+dx[i]*b, yk+dy[i]*a});
        st2.insert({xq+dx[i]*a, yq+dy[i]*b});
        st2.insert({xq+dx[i]*b, yq+dy[i]*a});
    }
    for(auto x:st1){
        if(st2.find(x)!=st2.end()) ans++;
    }
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