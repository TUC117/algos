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
#define yes() cout<<"YES"<<"\n"
#define no() cout<<"NO"<<"\n"
#define in(n) cin>>n
#define out(n) cout<<n<<"\n"

ll gcd(ll a,ll b)
{
    if(b>a) swap(a,b);
	if (b==0) return a;
	return gcd(b,a%b);
}

ll max(ll a,int b)
{
	if (a>b) return a;
	return b;
}

ll min(ll a,int b)
{
	if (a<b) return a;
	return b;
}
void swap(ll &a, ll &b){
    ll c = a;
    a = b;
    b = c;
}
void solve(){
    ll n; in(n);
    vec(ll) a(n);
    ll x = 0;
    fi(i,0,n){
        in(a[i]);
    }
    if(a[0]==1) yes();
    else no();
}

int main(){
    juuui();
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
}
