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
  int n; in(n);
  vec(int) a(n);
  for(auto&i:a) in(i);
  int i1 = 0, i2 = 0, i3 = 0;
  while(i1<n){
	i2 = i1+1;
	while(i2<n){
		if(a[i2] > a[i1] ){
			break;
		}
		else i2++;
	}
	if(i2!=n){
		i3 = i2 + 1;
		while(i3<n){
			if(a[i3] < a[i2]){
				break;
			}
			else i3++;
		}
		if(i3!=n) break;
	}
	i1++;
  }
  if(i1!=n){
	yes();
	out(i1+1<<" "<<i2+1<<" "<<i3+1);
  }
  else no();
}
int main(){
    juuui();
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
}
