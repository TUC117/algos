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

bool comparePosters(const pair<pair<Point, Point>, float>& a, const pair<pair<Point, Point>, float>& b) {
    return a.first.first.X() < b.first.first.X();
}

float length(vector <pair<pair<Point, Point>,float>> posters){
	float lenCov = posters[0].first.second.X()-posters[0].first.first.X();
	float MaxX = posters[0].first.second.X();
	for(auto p:posters){
			if(MaxX < p.first.second.X()){
				MaxX = max(MaxX, p.first.first.X());
				lenCov += -MaxX + p.first.second.X();
				MaxX = p.first.second.X();
		 }
	}
	return lenCov;
}
int main(){
	   /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int n;
	cin >> n;
	float a,b,c,d;

	vector <pair<pair<Point, Point>,float>> posters; 


	for(int i=0; i<n; i++){
		cin >> a;
		cin >> b;
		cin >> c;
		cin >> d;
		float slope;
		if(c!=a) slope = (float)(d-b)/(c-a);
		else slope = 1e18;
		posters.push_back(make_pair( make_pair(Point(a,b), Point(c,d)),slope));
	}

	float lengthCovered =0; 
	float area =0;
	
	// Sorting the posters in increasing order of their c
	



	for(int i=0;i<n;i++){
		cout<<posters[i].first.first.X()<<" "<<posters[i].first.first.Y()<<" "<<posters[i].first.second.X()<<" "<<posters[i].first.second.Y()<<" "<<posters[i].second<<endl;
	}
	
	// cout<<areaOfTwoTrapiziums(posters[0],posters[1])<<endl;
	sort(posters.begin(), posters.end(), comparePosters);
	lengthCovered = length(posters);
	cout << static_cast<int>(lengthCovered)<< endl;
	
	cout << static_cast<int>(area)<< endl;

	return 0; 
}

