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
    string s,t;
    in(s>>t);
    ll j = t.size()-1, i = s.size()-1;
    map<char,int> sm,tm;
    // for()
    while(j>=0 && i>=0){
        while(j>=0 && i>=0 && t[j]!=s[i]){
            i--;
            sm[s[i]]++;
        }
        tm[t[j]]++;
        j--;
        i--;
    }
    if(j>0) no();
    else{
        for(auto k : tm){
            if(sm[k.first] < k.second){
                no();
                return;
            }
        }
        yes();
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
