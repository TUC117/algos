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
    ll n, t;
    cin >> n >> t;
    string s; in(s);
    while(t--){
        for(int i=0;i<n-1;i++){
            if(s[i]=='B'&&s[i+1]=='G'){
                swap(s[i], s[i+1]);
                i++;
            }
        }
    }
    out(s);
}
int main(){
    juuui();
    int tt=1;
    // cin>>tt;
    while(tt--){
        solve();
    }
}
