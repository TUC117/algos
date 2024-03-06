#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define fi(i,a,b) for(ll i(a);i<b;i++)
#define fd(i,a,b) for(ll i(a);i>=b;i--)
#define vec(x) vector<x>
void solve(){
    ll n;
    cin>>n;
    vec(ll) a(n);
    for(auto&i:a) cin>>i;
    ll x=a[0];
    if(n%2==0){
        cout<<2<<"\n";
        cout<<1<<" "<<n<<"\n";
        cout<<1<<" "<<n<<"\n";
    }
    else{
        cout<<4<<"\n";
        cout<<1<<" "<<n<<"\n";
        cout<<2<<" "<<n<<"\n";        
        cout<<1<<" "<<2<<"\n";        
        cout<<1<<" "<<2<<"\n";        
    }
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
