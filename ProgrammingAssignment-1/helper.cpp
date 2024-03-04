#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Point {
 public:
  float x;
  float y;

 public:
  Point()
      : x(0), y(0) {}  // Default constructor initializing coordinates to (0,0)
  Point(float xVal, float yVal)
      : x(xVal), y(yVal) {}  // Parameterized constructor

  float X() const { return x; }  // Accessor for x coordinate
  float Y() const { return y; }  // Accessor for y coordinate

  
};

bool comparePosters(const std::pair<Point, Point>& a, const std::pair<Point, Point>& b) {
    return a.first.X() < b.first.X();
}

float length(vector<pair<Point, Point>> posters){
	float lenCov = posters[0].second.X()-posters[0].first.X();
	float MaxX = posters[0].second.X();
	for(auto p:posters){
			if(MaxX < p.second.X()){
				MaxX = max(MaxX, p.first.X());
				lenCov += -MaxX + p.second.X();
				MaxX = p.second.X();
		 }
	}
	return lenCov;
}
int main(){
	   /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int n;
	cin >> n;
	float a,b,c,d;

	vector <pair<Point, Point>> posters; 


	for(int i=0; i<n; i++){
		cin >> a;
		cin >> b;
		cin >> c;
		cin >> d;
		posters.push_back(make_pair(Point(a,b), Point(c,d)));
	}

	float lengthCovered =0; 
	float area =0;
	
	// Sorting the posters in increasing order of their c
	stable_sort(posters.begin(), posters.end(), comparePosters);



	// for(int i=0;i<n;i++){
	// 	cout<<posters[i].first.X()<<" "<<posters[i].first.Y()<<" "<<posters[i].second.X()<<" "<<posters[i].second.Y()<<endl;
	// }
	lengthCovered = length(posters);
	// cout<<areaOfTwoTrapiziums(posters[0],posters[1])<<endl;
	
 
	cout << static_cast<int>(lengthCovered)<< endl;
	
	cout << static_cast<int>(area)<< endl;

	return 0;
}

