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
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(ll& i: a) cin>>i;
    if(k==1){

        fi(i,0,n-1){
            if(a[i]>a[i+1]){
                cout<<"NO"<<"\n";
                return;
            }
        }
    }
    cout<<"YES"<<"\n";
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