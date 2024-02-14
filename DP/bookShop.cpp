#include<bits/stdc++.h>

int bookshop(int n, int x, int price[], int pages[]){
    bool weight[n+1][x+1];
    weight[0][0] = 1;
    int maxprice[n+1][x+1];
    for( int i=1;i<=x;i++) {weight[0][i] = 0;
    maxprice[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            weight[i][j] = 0;
            maxprice[i][j] = 0;
        }
    }
    maxprice[0][0] = 1;
    //     for(int j=0;j<=n;j++){
    // for(int i=0;i<=x;i++){
        
    //         // std::cout<<weight[j][i]<<" ";
    //         std::cout<<maxprice[j][i]<<" ";
    //     }
    //     std::cout<<std::endl;
    // }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            int max1 = 0, max2=0;
            if(j-price[i-1] >=0) {
                weight[i][j] |= weight[i-1][j-price[i-1]];
                max1 = maxprice[i][j] + pages[i-1]
            if(weight[i][j]){
                maxprice[i][j] += pages[i-1];
            }
            }
            weight[i][j] |= weight[i-1][j];
            // maxprice[i][j] += pages[i-1]
            if(weight[i][j]){
                maxprice[i][j] += pages[i-1];
            }
        }
    }
    // for(int j=0;j<=n;j++){
    // for(int i=0;i<=x;i++){
        
    //         // std::cout<<weight[j][i]<<" ";
    //         std::cout<<maxprice[j][i]<<" ";
    //     }
    //     std::cout<<std::endl;
    // }
    return -1;
}
int main(){
    int n, x;
    std::cin>>n>>x;
    int price[n];
    int pages[n];
    for(int i=0;i<n;i++) std::cin>>price[i];
    for(int i=0;i<n;i++) std::cin>>pages[i];
    std::cout<<bookshop(n,x,price,pages)<<"\n";
}