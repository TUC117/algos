#include<bits/stdc++.h>

#define ll long long
#define cin std::cin
#define cout std::cout
#define mp make_pair

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin>>n>>m;
    char room[n][m];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>room[i][j];
        }
    }

    ll ans = 0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(room[i][j]=='.' && !vis[i][j])
        }
    }


}