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

float slope (pair<Point, Point> p) {
    float m;
    // CHECK FOR THE PERPENDICULAR CASE
    m = float(p.second.Y() - p.first.Y())/float(p.second.X() - p.first.X());
    return m;
}

void merge_outlines(vector<pair<Point, Point>> p1, vector<pair<Point, Point>> p2, vector<pair<Point, Point>> &p3) {
    int i=0;
    int k = 0;
    for (i = 0; i < p1.size() + p2.size(); i++) {
        if (p1[i].first.X() < p2[0].first.X() && p2[0].first.X() <= p1[i].second.X()) {
            break;
        }
        if (i < p1.size()) p3.push_back(p1[i]);
        else p3.push_back(p2[i]);
    }
    for(int j = 0; j < p2.size() && i < p1.size(); j++){
            if (p2[j].first.X() >= p1[i].second.X()) {
                p3.push_back(p1[i]); i++; 
                if (i == p1.size() || j == p2.size()) {p3.push_back(p2[j]);}
            }
            else if (p2[j].second.X() <= p1[i].second.X()) {
                if ((p2[j].first.Y() - p1[i].first.Y()) <= (p2[j].first.X() - p1[i].first.X()) * (slope(p1[i]))) {
                    if ((p1[i].second.X() - p2[j].second.X()) * (slope(p1[i])) > (p1[i].second.Y() - p2[j].second.Y())) {
                        float x = (p2[j].first.X() * slope(p2[j]) - p1[i].first.X() * slope(p1[i]) + p1[i].first.Y() - p2[j].first.Y())/(slope(p2[j]) - slope(p1[i]));
                        float y = p1[i].first.Y() + (x - p1[i].first.X()) * slope(p1[i]);
                        float z = p1[i].second.Y() + slope(p1[i]) * (p2[j].second.X() - p1[i].second.X());
                        p3.push_back(make_pair(p1[i].first, Point(x, y)));
                        p3.push_back(make_pair(Point(x, y), p2[j].second));
                        bool b = false;
                        if (p2[j].second.X() == p1[i].second.X()) {i++;b=true;}
                        else {p1[i].first = Point(p2[j].second.X(), z);} 
                        if(b) {if (i == p1.size() || j == p2.size()) {p3.push_back(make_pair(Point(p2[j].second.X(), z), p1[i-1].second));}}
                        else {if (i == p1.size() || j == p2.size()) {p3.push_back(make_pair(Point(p2[j].second.X(), z), p1[i].second));}}
                    }
                    else if ((p1[i].second.X() - p2[j].second.X()) * (slope(p1[i])) <= (p1[i].second.Y() - p2[j].second.Y())) {
                        p3.push_back(p1[i]);
                    }
                }
                else {
                    float y = p1[i].first.Y() + slope(p1[i]) * (p2[j].first.X() - p1[i].first.X());
                    float z = p1[i].second.Y() + slope(p1[i]) * (p2[j].second.X() - p1[i].second.X());
                    float x1 = (p2[j].first.X() * slope(p2[j]) - p1[i].first.X() * slope(p1[i]) + p1[i].first.Y() - p2[j].first.Y())/(slope(p2[j]) - slope(p1[i]));
                    float y1 = p1[i].first.Y() + (x1 - p1[i].first.X()) * slope(p1[i]);
                    p3.push_back(make_pair(p1[i].first, Point(p2[j].first.X(), y)));
                    if ((p1[i].second.X() - p2[j].second.X()) * (slope(p1[i])) >= (p1[i].second.Y() - p2[j].second.Y())) {
                        p3.push_back(p2[j]);
                        bool b = false;
                        if (p2[j].second.X() == p1[i].second.X()) {i++;b = true;}
                        else {p1[i].first = Point(p2[j].second.X(), z);}
                        if(b){if (i == p1.size() || j == p2.size()) {p3.push_back(make_pair(Point(p2[j].second.X(), z), p1[i-1].second));}}
                        else {if (i == p1.size() || j == p2.size()) {p3.push_back(make_pair(Point(p2[j].second.X(), z), p1[i].second));}}
                    }
                    else {
                        p3.push_back(make_pair(p2[j].first, Point(x1, y1)));
                        p1[i].first = Point(x1, y1);
                        if (i == p1.size() || j == p2.size()) {p3.push_back(make_pair(Point(x1, y1), p1[i].second));}
                    }
                }
            }
            else if (p2[j].second.X() > p1[i].second.X()) {
                if ((p2[j].first.Y() - p1[i].first.Y()) < (p2[j].first.X() - p1[i].first.X()) * (slope(p1[i]))) {
                    float y = p2[j].second.Y() + slope(p2[j]) * (p1[i].second.X() - p2[j].second.X());
                    if (y <= p1[i].second.Y()) {
                        p3.push_back(p1[i]); i++;
                        p2[j].first = Point(p1[i].second.X(), y); j--;
                        if (i == p1.size() || j == p2.size()) {p3.push_back(make_pair(Point(p1[i-1].second.X(), y), p2[j+1].second));}
                    }
                    else if (y > p1[i].second.Y()) {
                        float x1 = (p2[j].first.X() * slope(p2[j]) - p1[i].first.X() * slope(p1[i]) + p1[i].first.Y() - p2[j].first.Y())/(slope(p2[j]) - slope(p1[i]));
                        float y1 = p1[i].first.Y() + (x1 - p1[i].first.X()) * slope(p1[i]);
                        p3.push_back(make_pair(p1[i].first, Point(x1, y1))); i++;
                        p2[j].first = Point(x1, y1); j--;
                        if (i == p1.size() || j == p2.size()) {p3.push_back(make_pair(Point(x1, y1), p2[j+1].second));}
                    }
                }
                else {
                    float y1 = p1[i].first.Y() + (p2[j].first.X() - p1[i].first.X()) * slope(p1[i]);
                    p3.push_back(make_pair(p1[i].first, Point(p2[j].first.X(), y1)));
                    if ((p1[i].second.X() - p2[j].second.X()) * (slope(p2[j])) >= (p1[i].second.Y() - p2[j].second.Y())) {
                        j--; i++;
                        if (i == p1.size() || j == p2.size()) {p3.push_back(p2[j+1]);}
                    }
                    else {
                        float x = (p2[j].first.X() * slope(p2[j]) - p1[i].first.X() * slope(p1[i]) + p1[i].first.Y() - p2[j].first.Y())/(slope(p2[j]) - slope(p1[i]));
                        float y = p1[i].first.Y() + (x - p1[i].first.X()) * slope(p1[i]);
                        float y2 = p2[j].second.Y() + (p1[i].second.X() - p2[j].second.X()) * slope(p2[j]);
                        p3.push_back(make_pair(p2[j].first, Point(x, y)));
                        p3.push_back(make_pair(Point(x, y), p1[i].second)); 
                        p2[j].first = Point(p1[i].second.X(), y2); j--;i++;
                        if (i == p1.size() || j == p2.size()) {p3.push_back(make_pair(Point(p1[i-1].second.X(), y2), p2[j+1].second));}
                        
                    }
                }
            }
    }
}

vector<pair<Point, Point>> merge(vector<pair<Point, Point>> p, int left, int right) {
    vector<pair<Point, Point>> p_1;
    if (left == right) {
        p_1.push_back(p[left]);
    }
    else if (left < right) {
        int mid = left + (right - left)/2;
        vector<pair<Point, Point>> p1 = merge(p, left, mid);
        vector<pair<Point, Point>> p2 = merge(p, mid+1, right);
        merge_outlines(p1, p2, p_1);
    }
    return p_1;
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
	
	sort(posters.begin(), posters.end(), [](const pair<Point, Point> &P1, const pair<Point, Point> &P2) {
	    return P1.first.X() < P2.first.X();
	});
	
	float b1 = posters[0].second.X();
	
	for (int i = 0; i < n; i++) {
	    lengthCovered += (posters[i].second.X() - posters[i].first.X());
	    if (i > 0) {
	        if (posters[i].first.X() <= b1 && posters[i].second.X() > b1) {
	            lengthCovered -= (b1 - posters[i].first.X()); 
	        }
	        else if (posters[i].first.X() <= b1 && posters[i].second.X() <= b1) {
	            lengthCovered -= (posters[i].second.X() - posters[i].first.X());
	        }
	        if (posters[i].second.X() > b1) {b1 = posters[i].second.X();}
	    }
	}
	vector <pair<Point, Point>> posters1 = merge(posters, 0, n-1);
	for (int i = 0; i < posters1.size(); i++) {
	    cout << posters1[i].first.X() << " " << posters[i].first.Y() << " " << posters[i].second.X() << " " << posters[i].second.Y() << endl;
	}
	for (int i = 0; i < posters1.size(); i++) {
	    area += (0.5) * (posters1[i].second.X() - posters1[i].first.X()) * (posters1[i].first.Y() + posters1[i].second.Y());
	} 

	cout << static_cast<int>(lengthCovered)<< endl;
	cout << static_cast<int>(area)<< endl;
	return 0;
}

