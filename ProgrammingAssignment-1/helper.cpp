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

float areaOfTwoTrapiziums(pair<Point, Point> A, pair<Point, Point> B){
	float ax1 = A.first.X();
	float ax2 = A.second.X();
	float ay1 = A.first.Y();
	float ay2 = A.second.Y();

	float bx1 = B.first.X();
	float bx2 = B.second.X();
	float by1 = B.first.Y();
	float by2 = B.second.Y();

	// Finding the individual areas;
	float arrTrep1 = abs(ax2-ax1)*(ay1+ay2)*0.5;
	float arrTrep2 = abs(bx2-bx1)*(by1+by2)*0.5;

	// Finding the intersecting part of the area
	float commonbase = min(ax2,bx2) - max(ax1,bx1);

	// Case - 1: Not intersecting
	if(commonbase<=0) return arrTrep1+arrTrep2;

	// Case - 2: Partialy intersecting
	// Subcases where intersecting part is a trapezium
	float check1 = (ay2-ay1)/(ax2-ax1)*(bx1-ax1) + ay1;
	if(ay2>by1 && check1>=by1){
		// ay2 will intersect the line at some poin
		float y = ((by1-by2)*bx1 - (bx1-bx2)*by1)/(by1-by2-bx1+bx2);
		float intersect = (0.5)*(commonbase)*(by1+y);
		return arrTrep1+arrTrep2-intersect;
	}
	float check2 = (by2-by1)/(bx2-bx1)*(ax2-bx1) + by1;
	if(ay2<by1 && check2 >=ay2){
		float y = ay2 - ((ay1-ay2)/(ax1-ax2))*(commonbase);
		float intersect = (0.5)*(commonbase)*(y+ay2);
		return arrTrep1+arrTrep2-intersect;
	}

	// Subcases where intersecting part is two trapeziums 
	
 	return -1.0;

}

int main(){
	   /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int n;
	cin >> n;
	float a,b,c,d;

	vector <pair<Point, Point> > posters; 

	for(int i=0; i<n; i++){
		cin >> a;
		cin >> b;
		cin >> c;
		cin >> d;
		posters.push_back(make_pair(Point(a,b), Point(c,d)));	
	}

	float lengthCovered =0; 
	float area =0;
	// for(int i=0;i<n;i++){
	// 	cout<<posters[i].first.X()<<" "<<posters[i].first.Y()<<" "<<posters[i].second.X()<<" "<<posters[i].second.Y()<<endl;
	// }
	cout<<areaOfTwoTrapiziums(posters[0],posters[1])<<endl;
 
	cout << static_cast<int>(lengthCovered)<< endl;
	
	cout << static_cast<int>(area)<< endl;

	return 0;
}

