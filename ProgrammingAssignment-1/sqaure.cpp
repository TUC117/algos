#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n; cin>>n;
    vector<pair<int,int>> coor(n);
    for(auto &i:coor){
        cin>>i.first>>i.second;
    }
    for(auto &i:coor){
        // cin>>i.first>>i.second;
        cout<<i.first<<" "<<i.second<<endl;
    }
    
}