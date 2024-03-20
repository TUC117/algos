/*
    AUTHOR - TUK04
*/

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
    ll n,m,k;
    in(n>>m>>k);
    vec(ll) a(n), b(m);
    for(auto&i:a) in(i);
    for(auto&i:b) in(i);
    ll ans = 0;
    fi(i,0,n){
        fi(j,0,m){
            if(a[i]+b[j] <= k) ans++;
        }
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
