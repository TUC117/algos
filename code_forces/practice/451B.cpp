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
        ll i,j,k;
        ll n,count=0;
        ll seg=0;
        ll l,r;

        cin>>n;
        ll a[n],s[n];

        for(i=0;i<n;i++)
        {
            cin>>a[i];
            s[i]=a[i];
        }

        sort(s,s+n);
        for(i=0;i<n;i++)
        {
            if(s[i]==a[i])
                count++;
        }

        if(count==n)
        {
            cout<<"yes\n1 1";
            return;
        }

        for(i=0;i<n-1,seg<1;)
        {
            if(a[i]<a[i+1])
            {
                i++;
            }
            else
            {
                l=i;
                r=i;
               while(a[i]>a[i+1] && i<n-1)
               {
                   i++;
                   r++;
               }
               sort(a+l,a+r+1);
               seg++;
            }}
        for(i=0;i<n;i++) {if(s[i]!=a[i]) {cout<<"no"; return;}}

        cout<<"yes\n"<<l+1<<" "<<r+1;    
}
int main(){
    juuui();
    int tt=1;
    // cin>>tt;
    while(tt--){
        solve();
    }
}
