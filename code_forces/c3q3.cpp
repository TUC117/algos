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
    ll aa; in(aa);
    string a; in(a);
    ll index = 0;
    ll ans = 0;
    ll n = a.size();
    while(index<a.size()){
            while(index<n-3 && a[index]=='m' && a[index+1]=='a' && a[index+2]=='p'){
                ans++;
                if(a[index+3]=='i'){
                    index+=2;
                }
                else index+=3;
            }
            while(index<n-2 && a[index]=='p' && a[index+1]=='i' && a[index+2]=='e'){
                ans++;
                index+=3;
            }
            if(index==n-3){
                if((a[index]=='p' && a[index+1]=='i' && a[index+2]=='e') || (a[index]=='m' && a[index+1]=='a' && a[index+2]=='p')){
                    ans++;
                    index+=3;
                }
            }
            // if(a[index]!='m' && a[index]!='p') index++;
            if(a[index]!='m') index++;
            else{
                if(a[index]!='a') index++;
                else{
                    if(a[index]!='p') inde
                }
            }
    }
    out(ans);
}
int main(){
    juuui();
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
}
