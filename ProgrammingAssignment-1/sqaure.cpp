// #include<iostream>
// #include<vector>
// using namespace std;

// int main(){
//     int n; cin>>n;
//     vector<pair<int,int>> coor(n);
//     for(auto &i:coor){
//         cin>>i.first>>i.second;
//     }
//     for(auto &i:coor){
//         // cin>>i.first>>i.second;
//         cout<<i.first<<" "<<i.second<<endl;
//     }
    
// }
// C++ program to find total area of two
// overlapping Rectangles
#include <bits/stdc++.h>
using namespace std;

struct Point {
	int x, y;
};

// Returns Total Area of two overlap
// rectangles
int overlappingArea(Point l1, Point r1, 
					Point l2, Point r2)
{
	int area1 = abs(l1.x - r1.x)*abs(l1.y - r1.y);

	// Area of 2nd Rectangle
	int area2 = abs(l2.x - r2.x) 
	* abs(l2.y - r2.y);

	// Length of intersecting part i.e
	// start from max(l1.x, l2.x) of
	// x-coordinate and end at min(r1.x,
	// r2.x) x-coordinate by subtracting
	// start from end we get required
	// lengths
	int x_dist = min(r1.x, r2.x) 
				- max(l1.x, l2.x);
	int y_dist = (min(r1.y, r2.y) 
				- max(l1.y, l2.y));
	int areaI = 0;
	if( x_dist > 0 && y_dist > 0 )
	{
		areaI = x_dist * y_dist;
	}
	
	return (area1 + area2 - areaI);
}

// Driver Code
int main()
{
	Point l1 = { 2, 2 }, r1 = { 5, 7 };
	Point l2 = { 3, 4 }, r2 = { 6, 9 };

	// Function Call
	cout << overlappingArea(l1, r1, l2, r2);
	return 0;
}
