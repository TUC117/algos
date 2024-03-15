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
ll abs(ll a, ll b){
	return max(a,b) - min(a,b);
}
void solve(){
	ll n; in(n);
	vec(ll) a(n);
	map<ll,ll> count;
	for(auto &i:a){
		in(i);
		count[i]++;
	}
	    // for (auto i = count.begin(); i != count.end(); i++)         cout << i->first << " "<< i->second <<" "<<n<< endl; 		

	if(count.size()>2 || count.size()==0 ) no();
	else if(count.size()==1) yes();
	else{
		auto it = count.begin();
		ll a= it->second;it++;
		ll b = it->second;
		if(n%2==0 && abs(a,b) == 0) yes();
		else if(n%2==1 && abs(a,b)==1) yes();
		else no();
	}
	return;

}
int main(){
    juuui();
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
}
