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
#define cin(n) cin>>n
#define cout(n) cout<<n<<"\n"

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

void solve(){
    ll n; cin(n);
    vec(ll) a(n);
    ll prev =  0;
    for(auto&i:a){
         cin(i);
         if(i==1) i++;
         if(prev==0) {
            prev = i;
        }
         else{
            if(i%prev==0){
                 i++;
            }
            prev = i;
         }
         cout<<prev<<" ";
    }
    cout<<"\n";


}
int main(){
    juuui();
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
}
