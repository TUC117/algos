#include <cmath>
#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
float epsilon =  1e-10;

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

// List of all the functions declared:

bool onSegment(Point p, Point q, Point r);
int orientation(Point p, Point q, Point r);
bool doIntersect(Point p1, Point q1, Point p2, Point q2);
Point lineIntersection (Point a, Point b, Point c, Point d);
void mergeOutlines(vector<Point>& outline, vector<Point>& a, vector<Point>& b);
void computeOutline(vector<Point>& outline, vector<pair<Point, Point>>& posters, int i, int j);
float calculateArea(vector<pair<Point, Point>> posters);
int aboveLine(Point a, Point b, Point c);
bool comparePair(pair<Point, Point> p1, pair<Point, Point> p2);
float length (vector<pair<Point, Point>> posters);

// Given three collinear points p, q, r, the function checks if point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r) 
{ 
    if (q.X() <= max(p.X(), r.X()) && q.X() >= min(p.X(), r.X()) && 
        q.Y() <= max(p.Y(), r.Y()) && q.Y() >= min(p.Y(), r.Y())) {
			return true;
		}
    return false; 
}

int orientation(Point p, Point q, Point r) {
    int val = (q.Y() - p.Y()) * (r.X() - q.X()) - (q.X() - p.X()) * (r.Y() - q.Y());
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4) 
        return true; 
  
    // Special Cases 
    // p1, q1 and p2 are collinear and p2 lies on segment p1q1 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true; 
  
    // p1, q1 and q2 are collinear and q2 lies on segment p1q1 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
  
    // p2, q2 and p1 are collinear and p1 lies on segment p2q2 
    if (o3 == 0 && onSegment(p2, p1, q2)) return true; 
  
     // p2, q2 and q1 are collinear and q1 lies on segment p2q2 
    if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
  
    return false;
}

Point lineIntersection (Point a, Point b, Point c, Point d) {
	float a1 = b.Y() - a.Y();
    float b1 = a.X() - b.X();
    float c1 = a1*(a.X()) + b1*(a.Y());

	float a2 = d.Y() - c.Y();
    float b2 = c.X() - d.X();
    float c2 = a2*(c.X()) + b2*(c.Y());

	float determinant = a1*b2 - a2*b1;

	if(abs(determinant) < epsilon) {
		return Point(-1,-1);
	}
	else {
		float x = (b2*c1 - b1*c2) / determinant;
		float y = (a1*c2 - a2*c1) / determinant;
		return Point(x,y);
	}
}

void mergeOutlines(vector<Point>& outline, vector<Point>& a, vector<Point>& b) {
	int i=0; int j=0;

	if(a[i].X() <= b[j].X()) {
		while(a[i].X() <= b[j].X() && i < a.size()) {
			outline.push_back(a[i]);
			i++;
		}
	}
	else {
		while(b[j].X() <= a[i].X() && j < b.size()) {
			outline.push_back(b[j]);
			j++;
		}
	}

	while(i < a.size() && j < b.size()) {
		// cerr << "1" << endl;
		if(a[i].X() < b[j].X() && a[i].Y() == 0 && b[j].Y() == 0) {
			if(i == 0) {
				outline.push_back(a[i]);
				i++;
				continue;
			}
			else {
				if(i != 0) {
					if(a[i-1].Y() == 0 && a[i-1].X() != a[i].X()) {
						outline.push_back(a[i]);
						i++;
						continue;
					}
				}
			}
		}
		if(a[i].X() > b[j].X() && a[i].Y() == 0 && b[j].Y() == 0) {
			if(i == 0) {
				outline.push_back(b[j]);
				j++;
				continue;
			}
			else {
				if(j != 0) {
					if(b[j-1].Y() == 0 && b[j-1].X() != b[j].X()) {
						outline.push_back(b[j]);
						j++;
						continue;
					}
				}
			}
		}
		if(a[i].X() == b[j].X() && a[i].Y() == 0 && b[j].Y() == 0) {
			outline.push_back(a[i]);
			i++; j++;
			continue;
		}
		if(a[i].X() < b[j].X() && a[i].Y() == 0) {
			if(i == 0) {
				i++;
				continue;
			}
			else if(a[i].Y() == 0 && a[i-1].Y() == 0) {
				i++;
				continue;
			}
			else {
				if(a[i-1].Y() == 0) {
					i++;
					continue;
				}
			}
		}
		if(a[i].X() > b[j].X() && b[j].Y() == 0) {
			if(j == 0) {
				j++;
				continue;
			}
			else if(b[j].Y() == 0 && b[j-1].Y() == 0) {
				j++;
				continue;
			}
			else {
				if(i != 0) {
					if(a[i-1].Y() == 0) {
						j++;
						continue;
					}
				}
			}
		}
		if(a[i].X() < b[j].X()) {
			if(aboveLine(b[j], b[j-1], a[i]) == 0) {
				outline.push_back(a[i]);
				i++; continue;
			}
			else if(aboveLine(b[j], b[j-1], a[i]) > 0) {
				if(doIntersect(a[i], a[i-1], b[j], b[j-1])) {
					outline.push_back(lineIntersection(a[i], a[i-1], b[j], b[j-1]));
				}
				outline.push_back(a[i]);
				i++;
				continue;
			} else {
				if (doIntersect(a[i], a[i-1], b[j], b[j-1])) {
					outline.push_back(lineIntersection(a[i], a[i-1], b[j], b[j-1]));
				}
				i++;
				continue;
			}
		}
		if(a[i].X() == b[j].X()) {
			if(a[i].Y() < b[j].Y()) {
				if(doIntersect(a[i], a[i-1], b[j], b[j-1])) {
					outline.push_back(lineIntersection(a[i], a[i-1], b[j], b[j-1]));
				}
				outline.push_back(b[j]); j++;
				continue;
			}
			else if(a[i].Y() > b[j].Y()) {
				if(doIntersect(a[i], a[i-1], b[j], b[j-1])) {
					outline.push_back(lineIntersection(a[i], a[i-1], b[j], b[j-1]));
				}
				outline.push_back(a[i]); i++;
				continue;
			}
			else {
				outline.push_back(a[i]); i++; j++;
				continue;
			}
		}
		if(a[i].X() > b[j].X()) {
			if(aboveLine(a[i], a[i-1], b[j]) == 0) {
				outline.push_back(b[j]);
				j++; continue;
			}
			else if(aboveLine(a[i], a[i-1], b[j]) > 0) {
				if(doIntersect(a[i], a[i-1], b[j], b[j-1])) {
					outline.push_back(lineIntersection(a[i], a[i-1], b[j], b[j-1]));
				}
				outline.push_back(b[j]);
				j++;
				continue;
			}
			else {
				if(doIntersect(a[i], a[i-1], b[j], b[j-1])) {
					outline.push_back(lineIntersection(a[i], a[i-1], b[j], b[j-1]));
				}
				j++;
				continue;
			}
		}
		
	}
	if(i < a.size()) {
		for(i = i; i < a.size(); i++) {
			outline.push_back(a[i]);
		}
	}
	else {
		for(j = j ; j < b.size(); j++) {
			outline.push_back(b[j]);
		}
	}
}

void computeOutline(vector<Point>& outline ,vector<pair<Point, Point>>& posters, int i, int j) {
	if(j==i) {
		float a,b,c,d;
		a = posters[i].first.X();
		b = posters[i].first.Y();
		c = posters[i].second.X();
		d = posters[i].second.Y();
		outline.push_back(Point(a, 0));
		outline.push_back(Point(a,b));
		outline.push_back(Point(c,d));
		outline.push_back(Point(c, 0));
		return;
	}
	
	int mid = i + (j-i)/2;
	vector<Point> outline1;
	computeOutline(outline1, posters, i, mid);
	vector<Point> outline2;
	computeOutline(outline2, posters, mid+1, j);
	mergeOutlines(outline, outline1, outline2);

	// for debugging
	// for(auto i: outline) {
	// 	cout << "( " << i.X() << " , " << i.Y() << ") , ";
	// }
	// cout << endl;
}

float calculateArea(vector<pair<Point, Point>> posters) {
	sort(posters.begin(), posters.end(), comparePair);
	vector<Point> outline;
	computeOutline(outline, posters, 0, posters.size()-1);

	// for debugging
	for(auto i: outline) {
		cout  << i.X() << " " << i.Y() << endl;
	}

	float area = 0;
	for(int i=1; i<outline.size(); i++) {
		if(outline[i].X() == -1 ){
			continue;
		}
		area += 0.5 * (outline[i].X() - outline[i-1].X()) * (outline[i].Y() + outline[i-1].Y());
	}
	return area;
}

// Returns +ve if c lies above the line formed by joining a and b, remaining are obvious
int aboveLine(Point a, Point b, Point c) {
	if(a.X() != b.X()) {
		float v = ((a.Y()-b.Y())*c.X() + (b.Y()*a.X() - a.Y()*b.X())) / (a.X() - b.X());
		if(v < c.Y()) return 1;
		else if(v > c.Y()) return -1;
		else return 0;
	}
	return -2;
}

// Comparing starting points of the intervals
bool comparePair(pair<Point, Point> p1, pair<Point, Point> p2) {
	return (p1.first.X() < p2.first.X());
}

// Function to calculate length covered on x-axis
float length (vector<pair<Point, Point>> posters) {
	// Sorting according to starting points
	sort(posters.begin(), posters.end(), comparePair);
	pair<Point, Point> previous = posters[0];
	float length = previous.second.X() - previous.first.X();
	for(auto interval : posters) {
		if(interval.first.X() > previous.second.X()) {
			length += interval.second.X() - interval.first.X();
			previous = interval;
		} else if(interval.second.X() > previous.second.X()) {
			length += interval.second.X() - previous.second.X();
			previous = interval;
		}
	}
	return length;
}

int main(){
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

	float lengthCovered = length(posters);
	float area = calculateArea(posters);
 
	cout << static_cast<int>(lengthCovered)<< endl;
	
	cout << static_cast<int>(area)<< endl;

	return 0;
}

