#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<int>> values;
int calls =0;
unsigned int setBitsToOne(const std::vector<int>& indices) {
    unsigned int number = 0; // Start with all bits set to 0
    for (int index : indices) {
        if(index!= -1)number |= (1U << index); // Set the bit at the given index to 1
    }
    return number;
}
vector<int> findIndependentVertices(vector<int>& subset) {
    vector<int> independentVertices;
    // Iterate over each vertex in the subset
    for (int i : subset) {
        if (i!= -1){bool isIndependent = true;
        // Check if there are any non-zero entries in the row corresponding to the vertex
        for (int j : subset) {
            if (j!=-1&&values[j][i] != 0&&j!=i) {
                isIndependent = false;
                break;
            }
        }
        // If the row is all zeros, add the vertex to the list of independent vertices
        if (isIndependent) {
            independentVertices.push_back(i);
        }
		}
    }
    return independentVertices;
}
int formula(int n,vector<int>subset){
	int sum = values[n][n];
	for(int i = 0;i<subset.size();i++){
		if(subset[i] == -1 && i!=n){
			sum += values[i][n];
		}
	};
	for(int i = 0;i<subset.size();i++){
		if(subset[i] != -1&&i!=n){
			sum += values[n][i];
		}
	};
	for(int i = 0;i<subset.size();i++){
		if(subset[i]==-1 && i!=n){
			for(int j = 0;j<subset.size();j++){
				if(subset[j] != -1 &&j!=n){
					sum += values[i][j];
				}
			}
		}
	}
	return sum;
}
int main_function(vector<int>&venky,vector<int>subset,int n){
	calls++;
	//int p =0;
	int min_value = INT32_MAX;
	//while(p<n){
		vector<int> vertices = findIndependentVertices(subset);
		int mint = setBitsToOne(subset);
		for(int v:vertices){
			subset[v] = -1;
			int pint = setBitsToOne(subset);
			if(venky[pint] == -1){
				int k = main_function(venky,subset,n);
			}
			
			min_value =min( max(formula(v,subset),venky[pint]) , min_value);

			// cout<<formula(v,subset)<<endl;
			subset[v] = v;
		}
		//p++;
	//}

	if(venky[mint] ==-1){ venky[mint]= min_value; }


	return min_value;
}
int main(){
	   /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int n; // number of processes
	
 
	cin >> n;
	
	vector< int > memory;  
	
	int a;
	for(int i=0; i<n; i++){
		vector<int> ram(n,0);
		for(int j=0; j<i; j++){
			cin >> a;
			ram[j] = a;};
		for(int j=i; j<n; j++){
			cin >> a;
			ram[j] = a;
			memory.push_back(a);
		}
		values.push_back(ram);
	}
	vector<int>venky(1<<n,-1);
	venky[0] = 0;
	int p = 0;
	vector<int> subset;
	for(int i = 0;i<n;i++){
		subset.push_back(i);
	};
	//return 0;
	cout<<main_function(venky,subset,n)<<endl;
	
  	//cout << values[2][2] << endl;
	
	return 0;
}
