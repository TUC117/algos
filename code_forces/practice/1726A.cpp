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

void solve(){
    ll n; in(n);
    vec(ll) a(n);
    ll maz = INT_MIN, mi0 = INT_MAX;
    fi(i,0,n){
        in(a[i]);
        if(i>0){
            maz = max(maz,a[i]);
        }
        if(i<n-1){
            mi0 = min(mi0,a[i]);
        }
    }
    ll ans = max(a[n-1]-a[0], maz - a[0]);
    ans = max(ans,a[n-1]-mi0);
    fi(i,0,n-1){
        ans = max(ans, a[i]-a[i+1]);
    }
    out(ans);
    

}
int main(){
    juuui();
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
}
