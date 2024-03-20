#include<iostream>
using namespace std;
typedef long long ll;

// ll calpow2(ll n){
//     if(n%2==0) return calpow2()
// }
int main(){
    ll n;
    cin>>n;
    ll ans = 1;
    while(n--){
        ans *= 2;
        ans %= 1000000007;
    }
    cout<<ans<<endl;
}