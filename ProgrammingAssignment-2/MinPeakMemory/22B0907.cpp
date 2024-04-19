#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void BinaryEncoding(int num, vector< int >& encoded, int& i){
	int rem = num % 2;
	int quo = num / 2;
	vector< int > temp;
	for(int k = 0; k < i; k++){
		temp.push_back(rem);
		rem = quo % 2;
		quo = quo / 2;
	}
	for(int k = 0; k < i; k++){
		encoded.push_back(temp[i-k-1]);
	}
}

int BinaryDecoding(vector< int >& encoded){
	int s = encoded.size();
	int two_pow = 1;
	int sum = 0;
	for(int k = s-1; k >= 0; k--){
		if(encoded[k]){
			sum = sum + two_pow;
		}
		two_pow = two_pow * 2;
	}
	return sum;
}

int isSizeOne(vector< int >& encoded){
	int sum = 0, k = 0;
	for(int i = 0; i < encoded.size(); i++){
		sum += encoded[i];
		if(encoded[i]){
			k = i;
		}
	}
	if(sum == 1){
		return k;   // If one element then index is returned
	}
	return -1; // If more than one element
}

bool notValidEnding(vector< vector< int > >& memory, vector<int>& encoding, int& j){
    bool flag = false;
    int n = memory.size();
    for(int i = 0; i < j; i++){
        if(encoding[i] == 1 && memory[n-j-1][n-i-1] > 0){
            flag = true;
        }
    }
    return flag;
}

int presentValueMem(vector< vector< int > >& memory, vector < int >& peakMem, vector < int >& encoded, int& j, int& num){
    
    int n = memory.size();
    int val1, val2, sum1 = 0, sum2 = 0, sum3 = 0;
    for(int k = 0; k < encoded.size(); k++){
        for(int i = k+1; i < encoded.size(); i++){
            if(encoded[i] == 1 && encoded[k] == 0 && i != j && k != j){
                sum3 = sum3 + memory[n-i-1][n-k-1];
            }
        }
    }
    for(int i = 0; i < encoded.size(); i++){
        if(encoded[i] && i > j){
            sum1 = sum1 + memory[n-i-1][n-j-1];
        }
    }
    for(int i = 0; i < encoded.size(); i++){
        if(encoded[i] == 0 && i < j){
            sum2 = sum2 + memory[n-j-1][n-i-1];
        }
    }
    val1 = memory[n-j-1][n-j-1] + sum1 + sum2 + sum3;
    val2 = peakMem[num];
    int max = val1;
    if(val2 > val1){
        max = val2;
    }
 
    return max;
}

void findPeakMem(vector< vector< int > >& memory, vector < int >& peakMem, int& i, int& n){
    vector<int> encoded;
    BinaryEncoding(i, encoded, n);
    int index = isSizeOne(encoded);

    if(peakMem[i] != -1){
		return;
	}

    if(index > -1){
        int sum = memory[n-index-1][n-index-1];
        for(int k = 0; k < index; k++){
            sum = sum + memory[n-index-1][n-k-1]; 
        }

        peakMem[i] = sum;
		return;
    }

    int num = 0;
    int min = INT32_MAX, temp = 0;
    for(int j = 0; j < encoded.size(); j++){
        if(encoded[j]){
            if(notValidEnding(memory, encoded, j)){
                continue;
            }
    
            encoded[j] = 0;
			num = BinaryDecoding(encoded);
    
            if(peakMem[num] == -1){
				findPeakMem(memory, peakMem, num, n);
			}

            temp = presentValueMem(memory, peakMem, encoded, j, num);
            if(temp < min){
                min = temp;
            }

            encoded[j] = 1;
        }
    }
    peakMem[i] = min;
}

int main(){
	   /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int n; // number of processes
	

	cin >> n;
	
	vector< vector< int > > memory;  
	
	int a;
	for(int i=0; i<n; i++){
        vector < int > temp;
		for(int j=0; j<n; j++){
			cin >> a;
			temp.push_back(a);
		}
        memory.push_back(temp);
	}
	
	vector < int > peakMem;
	for(int i = 0; i < pow(2, n); i++){
		peakMem.push_back(-1);
	}
	int max = pow(2, n) - 1;

	findPeakMem(memory, peakMem, max, n);

  	cout << peakMem[max] << endl;

	return 0;
}