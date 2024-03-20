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
    ll n; in(n);
    vec(ll) a(n);
    for(auto&i:a) in(i);
    bool flag = false;
    ll index = 0;
    while(index<n-1){
        if(a[index] > a[index+1]){
            if(index==0){
                if(a[index]/10 == 0){
                    no();
                    return;
                }
                if(a[index]/10 > a[index]%10){
                    no();
                    return;
                }
                if(a[index+1]>=10){
                    if(a[index]%10 > a[index+1]/10){
                        no();
                        return;
                    }
                }
                if(a[index+1]<10){
                    if(a[index]%10 > a[index+1]){
                        no();
                        return;
                    }                    
                }
                // index++;
            }
            else{
            ll temp = a[index]%10;
            ll temp1 = a[index]/10;
            if(temp1 == 0){
                no();
                return;
            }
            if(temp < temp1){
                no(); return;
            }
            if(a[index-1]%10 > temp1){
                no(); return;
            }

            if(a[index+1]>=10){
                    if(a[index]%10 > a[index+1]/10){
                        no();
                        return;
                    }
                }
            if(a[index+1]<10){
                    if(a[index]%10 > a[index+1]){
                        no();
                        return;
                }                    
            }
            // else index++;
            
            
        }
        }
        index++;
    }
    yes();
}
int main(){
    juuui();
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
}
