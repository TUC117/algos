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
	return gcd(b,a%b);\
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
    ll a, b, c;
    in(a>>b>>c);
    ll ans = 0;
    ans += a;
    ans += b/3;  
    b = b%3;
    if(b==0){
        ans+=c/3;

        // cout<<ans<<endl;
        ans += (bool)(c%3);
        
        out(ans);
        return;        
        
    }
    else if(b==1){
        if(c>=2){
            ans += 1;
            c -= 2;
            ans += c/3;
            ans += (bool)(c%3);
            out(ans);
            return;
            // if(c%3==0){
                
            // }
            // else{
            //     out(-1);
            //     return;
            // }
        }
        else{
                out(-1);
                return;            
        }
    }
    else{
        if(c>=1){
            ans += 1;
            c -= 1;
                ans += c/3;
                ans += (bool)(c%3);
                out(ans);
                return;            
            // if(c%3==0){

            // }
            // else{
            //     out(-1);
            //     return;
            // }
        }        
        else{
                out(-1);
                return;            
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
