#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    std::cin>>n;
    string s;
    std::cin>>s;
    
    if(s[0]<s[s.length()-1]){
        if(n%2==0){
            std::cout<<s<<"\n";
            return;
        }
    }
    else if(s[0]>s[s.length()-1]){
        string temp = s;
        std::reverse(temp.begin(), temp.end());
        std::cout<<temp<<s<<"\n";
        return;
    }
    
    int left = 0, right = s.length()-1;
    while(s[left]==s[right] && left < right){
        left++;
        right--;
    }
    if(s[left]<=s[right] || left >= right){
        std::cout<<s<<"\n";
    }
    else{
        string temp = s;
        std::reverse(temp.begin(), temp.end());
        std::cout<<temp<<s<<"\n";        
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t; std::cin>>t;
    while(t--){
        solve();
    }
}