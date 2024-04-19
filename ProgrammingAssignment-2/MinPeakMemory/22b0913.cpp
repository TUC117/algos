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
	vec(ll) pre_mem(1<<n);
	vec(bool) pre_mem1(1<<n);
	ll s3 = 0;
	vec(ll) temp;
	bool is_valid = true;
	fi(subset, 0, 1<<n){
		s3 = 0;
		temp.clear();
		fi(i,0,n){
			if(subset & (1<<i)){
				temp.pb(i+1);
			}
		}
		#ifdef DEBUG
		fi(i,0,temp.size()){
			cout<<temp[i]<<" ";
		}
		cout<<endl;
		#endif		
		// Finding third term
		is_valid = true;
		fi(j,0,temp.size()){
			// if(i!=j){
				fi(k,0,n){
					if(!(subset & (1<<k))){
						// s3 += m[k][temp[j]-1];
						s3 += m[temp[j]-1][k];
						if(m[k][temp[j]-1]!=0) is_valid = false;
					}
				}
			// }
		}
		pre_mem[subset]=s3;
		pre_mem1[subset] = is_valid;
		#ifdef DEBUG
			cout << "s3 = "<<s3<<endl;
		#endif		
		
		
	}

	ll min_sub_sum = INT_MIN, index = 0;
	ll s1 = 0, s2 = 0;
	ll present_sum = s1 + s2 + s3;
	bool x;
	fi(subset, 0, 1<<n){

		// storing the processes which are present in the current subset
		// vec(ll) temp;
		temp.clear();
		fi(i,0,n){
			if(subset & (1<<i)){
				temp.pb(i+1);
			}
		}
		#ifdef DEBUG
		fi(i,0,temp.size()){
			cout<<temp[i]<<" ";
		}
		cout<<endl;
		#endif

		min_sub_sum = INT_MIN;
		index = 0;
		fi(i,0,temp.size()){
			#ifdef DEBUG
				cout << "i "<<i<<endl;
			#endif
			is_valid = true;
			x = true;
			fi(j,0 ,temp.size()){
				if(i!=j){
					if(m[temp[i]-1][temp[j]-1] != 0) x = false;
				}
			}			
			is_valid = pre_mem1[subset] & x;
			// bool is_valid = true;
			// fi(j,0 ,temp.size()){
			// 	if(i!=j){
			// 		if(m[temp[i]-1][temp[j]-1] != 0) is_valid = false;
			// 	}
			// 	fi(k,0,n){
			// 		if(!(subset & (1<<k))){
			// 			if(m[k][temp[j]-1]!=0) is_valid = false;
			// 		}
			// 	}
			// }
			if(is_valid == false) {continue;}

			s1 = 0;
			s2 = 0;
			s3 = 0;
			
			fi(j,0 ,temp.size()){
				s1 += m[temp[j] - 1][temp[i] - 1];
			}
			#ifdef DEBUG
				cout << "s1 = "<<s1<<endl;
			#endif

			// Finding second term
			fi(j,0,n){
				if(!(subset & (1<<j) )){
					// s2 += m[j][temp[i]-1];
					s2 += m[temp[i]-1][j];
				}
			}
			#ifdef DEBUG
				cout << "s2 = "<<s2<<endl;
			#endif			

			// // Finding third term
			// fi(j,0,temp.size()){
			// 	if(i!=j){
			// 		fi(k,0,n){
			// 			if(!(subset & (1<<k))){
			// 				// s3 += m[k][temp[j]-1];
			// 				s3 += m[temp[j]-1][k];
			// 			}
			// 		}
			// 	}
			// }
			// #ifdef DEBUG
			// 	cout << "s3 = "<<s3<<endl;
			// #endif
			s3 = pre_mem[subset]-pre_mem[1<<(temp[i]-1)];
			// s3 = pre_mem[subset];
			
 			
			present_sum = s1+s2+s3;
			// else{
			// ll summ = max(dp[subset ^ (1<<(temp[i]-1))], present_sum);
			dp[subset] = min(max(dp[subset ^ (1<<(temp[i]-1))], present_sum), dp[subset]);
			// }
		}
		// cout<<"dp["<<subset<<"] "<<dp[subset]<<endl;
	}
	
	out(dp[(1<<n)-1]);
}
int main(){
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */  
	jui();
	ll t = 1; 
	while(t--){
		solve();
	}

	return 0; 
}
