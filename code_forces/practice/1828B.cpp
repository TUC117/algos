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

ll gcd(ll a,ll b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}

void solve(){
    ll n,b,ans=0; cin>>n;
    fi(i,1,n+1){
        cin>>b;
        if(abs(b-i)){
            if(ans>abs(b-i)) ans = gcd(ans,abs(b-i));
            else ans = gcd(abs(b-i),ans);
            
        }

    }
    // vec(ll) b = a;
    // sort(all(a));
    // ll ans=INT_MAX;
    // fi(i,0,n){
    //     if(a[i]!=b[i]){
    //         if(ans==INT_MAX) ans = abs(a[i]-b[i]);
    //         else{
    //             // ans = gcd(ans,abs(a[i]-b[i]));
    //             if(abs(a[i]-b[i])< ans) if(ans%abs(a[i]-b[i]) == 0) ans = abs(a[i]-b[i]);
    //         }
    //     }
    // }
    cout<<ans<<"\n";
}
int main(){
    juuui();
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
}