#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define fi(i,a,b) for(ll i(a);i<b;i++)
#define fd(i,a,b) for(ll i(a);i>=b;i--)

void solve(){
    ll n,k;
    cin>>n>>k;
    string s;
    map<char,int> mm;
    cin>>s;
    for(auto c:s){
        mm[c]++;
    }
    ll odd = 0;
    for(auto C :mm){
        if(C.second%2!=0) odd++;
    }
    if(k<odd-1) cout<<"NO"<<"\n";
    else cout<<"YES"<<"\n";
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