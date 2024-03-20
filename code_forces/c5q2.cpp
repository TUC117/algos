/*
    AUTHOR - TUK04
*/

#include<bits/stdc++.h>
#include<algorithm>
#include <optional>

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
    ll n, k;
    in(n>>k);
    vec(ll) l(n);
    vec(ll) r(n);
    for(auto&i:l) in(i);
    for(auto&i:r) in(i);
    
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    // cout<<"VEC"<<"\n";
    // for(auto i : l) cout<<i<<" ";
    // cout<<"\n";
    // for(auto i : r) cout<<i<<" ";
    // cout<<"\n";

    // cout<<areElementsDistinct(l);
    vec(ll) res1;
    vec(ll) res2;
    map<ll, int> c1, c2;
    for(auto i : l) c1[i]++;
    for(auto i : r) c2[i]++;
    // cout<<"MAP"<<"\n";
    // for(auto i : l) cout<<c1[i]<<" ";
    // cout<<endl;
    // for(auto i : l) cout<<c2[i]<<" ";
    // cout<<endl;
    // bool repeated = false;

    for(auto&i : l){
        if(c1[i]>1){
            // repeated = true;
            res1.pb(i);
            i = INT_MAX;
        }
    }
    // cout<<"RES"<<endl;
    // for(auto i : res1) cout<<i<<" ";
    // cout<<endl;
    for(auto&i : r){
        // cout<<"ghi";
        if(c2[i]>1){
            // repeated = true;

            res2.pb(i);
            // cout<<"hi "<<i<<endl
            i = INT_MAX;
        }
    }
    // for(auto i : res2) cout<<i<<" ";
    // cout<<endl;
    if(res1.size() >= 2*k){
        fi(i, 0, 2*k) cout<<res1[i]<<" ";
        cout<<"\n";
        fi(i, 0, 2*k) cout<<res2[i]<<" ";
        cout<<"\n";
    }
    else{
        ll index = 0;
        while(res1.size() <= 2*k && index<n){
            if(l[index]!=INT_MAX){
                res1.pb(l[index]);
            }
            index++;
        }
        index = 0;
        while(res2.size()<= 2*k && index<n){
            if(r[index]!=INT_MAX){
                res2.pb(r[index]);
            }
            index++;
        }  
        fi(i, 0, 2*k) cout<<res1[i]<<" ";
        cout<<"\n";
        fi(i, 0, 2*k) cout<<res2[i]<<" ";
        cout<<"\n";

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
