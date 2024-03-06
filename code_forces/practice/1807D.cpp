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
    ll n,q;
    cin>>n>>q;
    vec(ll) a(n);
    vec(ll) sum(n+1);
    fi(i,0,n) {
        cin>>a[i];
        sum[i+1] = sum[i]+a[i];
    }
    while(q--){
        ll l, r, k;
        cin>>l>>r>>k;
        if(sum[n]%2==0){
            
            if((sum[r] - sum[l-1])%2==0){
                // cout<<1<<"\n";
                if((r-l+1)%2==0) no();

                else{
                    if(k%2==0) no();
                    else yes();
                }
            }
            else{
                if((r-l+1)%2==0) yes();

                else{
                    if(k%2==0) yes();
                    else no();
                }              
            }
        }
        else{
            if((sum[r] - sum[l-1])%2==0){
                if((r-l+1)%2==0) yes();

                else{
                    if(k%2==0) yes();
                    else no();
                }
            }
            else{
                if((r-l+1)%2==0) no();

                else{
                    if(k%2==0) no();
                    else yes();
                }          
            }
        }
    }
    
    
}
int main(){
    juuui();
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
}