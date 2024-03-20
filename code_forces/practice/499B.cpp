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
    int n, m;
    cin >> n >> m;
    vec(string) a(m);
    vec(string) b(m);
    fi(i,0,m){
        cin >> a[i];
        cin >> b[i];
    }
    vec(string) c(n);
    vec(string) ans;
    fi(i,0, n) cin>>c[i];
    fi(i,0,n){
        fi(j,0,m){
            if(c[i] == a[j]){
                if(a[j].size() <= b[j].size()) ans.pb(a[j]);
                else ans.pb(b[j]);
                break;
            }

        }
    }
    fi(i,0,n){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){
    juuui();
    int tt=1;
    // cin>>tt;
    while(tt--){
        solve();
    }
}
