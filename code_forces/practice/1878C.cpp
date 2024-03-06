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
    ll n,k,x;
    cin>>n>>k>>x;
    ll sk = (k*(k+1))/2;
    ll sn = n*k - ((k-1)*k)/2;
    if(x>=sk && x<=sn) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";

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