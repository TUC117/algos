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
#define take(a) for(auto&i:a) in(i);


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
    ll n, l;
    cin >> n >> l;
    vec(ll) a(n);
    take(a);
    sort(all(a));
    double ans;
    ans = (double)(a[0] - 0);
    fi(i,0,n-1){
        // ans = (float)max(ans, (float)((a[i+1] - a[i])/2.0));
        if(ans < ((a[i+1] - a[i])/2.0)){
            ans =((a[i+1] - a[i])/2.0);
        }
        // cout<<ans<<" ans ---- val  "<<(float)((a[i+1] - a[i])/2.0)<<endl;
    }
    // cout<<l - a[n-1]<<endl;
        if(ans <(l - a[n-1])){
            ans = (l - a[n-1]);
        }    
    // ans = (float)max(ans, l - a[n-1]);
    // out(ans);
    cout<<setprecision(15)<<ans<<endl;

}
int main(){
    juuui();
    int tt=1;
    // cin>>tt;
    while(tt--){
        solve();
    }
}
