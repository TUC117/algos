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

void solve(){
    ll n; cin>>n;
    string s; cin>>s;
    ll cg = 0, cl=0;
    ll index = 0;
    ll ans = INT_MIN;
    while(index<n){
        while(index<n&&s[index]=='<'){
            cg++;
            index++;
        }
        while(index<n&&s[index]=='>'){
            cl++;
            index++;
        }
        // index++;
        ll temp = max(cl, cg);
        ans = max(ans,temp);
        cl = 0;
        cg = 0;
    }
    cout<<ans+1<<"\n";
}
int main(){
    juuui();
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
}