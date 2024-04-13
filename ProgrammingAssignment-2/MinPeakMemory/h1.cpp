/*
	AUTHOR - TUK04
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

// #define DEBUG

// #define INT_MAX 1e9
typedef long long ll;
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define vec(x) vector<x> 
#define jui()  (ios_base:: sync_with_stdio(false),cin.tie(NULL));
#define in(n) cin>>n 
#define out(n) cout<<n<<"\n"
#define fi(i,a,b) for(ll i=a;i<b;i++)

void dout(string s){
	#ifdef DEBUG
		// out(s);
		cerr<<s<<endl;
	#endif		
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
	ll n;
	in(n);
	vec(vec(ll)) m(n, vec(ll)(n, 0));
	fi(i,0,n){
		fi(j,0,n){
			in(m[i][j]);
		}
	}
	vec(ll) dp((1<<n), INT_MAX);
	dp[0] = 0;
	fi(subset, 0, 1<<n){
		int p = __builtin_popcount(subset);
		fi(i,0,n){
			if(!(subset & (1<<i))){
				ll s = 0;
				fi(j,0,n){
					if(subset & (1<<j)){
						s += m[j][i];
					}
				}
				fi(j,0,n){
					if(!(subset & (1<<j)) && i!=j){
						s += m[i][j];
					}
				}
				dp[subset | (1<<i)] = min(dp[subset | (1<<i)], dp[subset] + s);
			}
		}
	}
	out(dp[(1<<n )-1]);
}
int main(){
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */  
	jui();
	ll t = 1; 
	// cin >> t;
	while(t--){
		solve();
	}

	return 0; 
}
