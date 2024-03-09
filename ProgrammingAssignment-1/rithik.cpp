#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define eps 1e-9

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

float slope(pair<Point, Point> p){
	float i = (p.second.Y() - p.first.Y())/(p.second.X()-p.first.X());
	return i;
}

float line(pair<Point, Point> p, float x){
	float m = slope(p);
	float y = m*(x-p.first.X()) + (p.first.Y());
	return y;
}

Point Intersection(pair<Point, Point> p1, pair<Point, Point> p2){
	float x = ((p1.first.Y()-p2.first.Y()) + (slope(p2)*p2.first.X()) - (slope(p1)*p1.first.X()))/(slope(p2)-slope(p1));
	float y = p1.first.Y() + slope(p1)*(x-p1.first.X());
	return Point(x, y);
}

void merge(vector<pair<Point, Point>>& pts, vector<pair<Point, Point>> pts1, vector<pair<Point, Point>> pts2){
	if(pts1.size() == 0){
		pts = pts2;
	}
	if(pts2.size() == 0){
		pts = pts1;
	}
	int i = 0,j = 0;
	while(i < pts1.size() && j < pts2.size()){
		if(pts2[j].first.X() > pts1[i].second.X() + eps){
			// cout << "1\n";
			pts.push_back(pts1[i]);
			i++;
		}
		// else if(pts2[j].second.X() < pts1[i].first.X()){
			// cout << "2\n";
			// cout << pts1[i].first.X() << endl;
		// 	pts.push_back(pts2[j]);
		// 	j++;
		// 
		else if(pts2[j].second.X() <= pts1[i].second.X()){
			if((line(pts1[i], pts2[j].first.X()) + eps > pts2[j].first.Y()) && (line(pts1[i], pts2[j].second.X()) + eps > pts2[j].second.Y())){
				// cout << "2\n";
				pts.push_back(make_pair(pts1[i].first, Point(pts2[j].second.X(), line(pts1[i], pts2[j].second.X()))));
				pts1[i].first = Point(pts2[j].second.X(), line(pts1[i], pts2[j].second.X()));
				if(abs(pts1[i].first.X() - pts1[i].second.X()) < eps){
					i++;
				}
				j++;
			}
			else if((line(pts1[i], pts2[j].first.X()) < pts2[j].first.Y()) && (line(pts1[i], pts2[j].second.X()) < pts2[j].second.Y())){
				// cout << "3\n";
				if(pts1[i].first.X() != pts2[j].first.X()){
					pts.push_back(make_pair(pts1[i].first, pts2[j].first));
				}
				pts.push_back(pts2[j]);
				pts1[i].first = Point(pts2[j].second.X(), line(pts1[i], pts2[j].second.X()));
				if(abs(pts1[i].first.X() - pts1[i].second.X()) < eps){
					i++;
				}
				j++;
			}
			else{
				if(line(pts1[i], pts2[j].second.X()) < pts2[j].second.Y()){
					// cout << "4\n";
					Point p;
					if(abs(pts1[i].first.X() - pts1[i].second.X()) > eps && abs(pts2[j].first.X() - pts2[j].second.X()) > eps){
						p = Intersection(pts1[i], pts2[j]);//cout<<p.X()<<" "<<p.Y()<<endl;
					}
					else if(abs(pts2[j].first.X() - pts2[j].second.X()) < eps){
						p = Point(pts2[j].first.X(), line(pts1[i], pts2[j].second.X()));
					}
					else{
						p = Point(pts1[i].first.X(), line(pts2[j], pts1[i].second.X()));
					}
					// if(p.X()>=1 || p.X()<1) {;}else{
					// 	cout << pts1[i].first.X() << " " << pts1[i].first.Y() << " " << pts1[i].second.X() << " " << pts1[i].second.Y() << endl;
					// cout << pts2[j].first.X() << " " << pts2[j].first.Y() << " " << pts2[j].second.X() << " " << pts2[j].second.Y() << endl;
					// }
					if(abs(p.X() - pts1[i].first.X()) > eps){
						pts.push_back(make_pair(pts1[i].first, p));
					}
					pts.push_back(make_pair(p, pts2[j].second));
					pts1[i].first = Point(pts2[j].second.X(), line(pts1[i], pts2[j].second.X()));
					if(abs(pts1[i].first.X() - pts1[i].second.X()) < eps){
						i++;
					}
					j++;
				}
				else{
					// cout << "5\n";
					// Point p = Intersection(pts1[i], pts2[j]);//cout<<p.X()<<" "<<p.Y()<<endl;
					Point p;
					if(abs(pts1[i].first.X() - pts1[i].second.X()) > eps && abs(pts2[j].first.X() - pts2[j].second.X()) > eps){
						p = Intersection(pts1[i], pts2[j]);//cout<<p.X()<<" "<<p.Y()<<endl;
					}
					else if(abs(pts2[j].first.X() - pts2[j].second.X()) < eps){
						p = Point(pts2[j].first.X(), line(pts1[i], pts2[j].second.X()));
					}
					else{
						p = Point(pts1[i].first.X(), line(pts2[j], pts1[i].second.X()));
					}
					// if(p.X()>=1 || p.X()<1) {;}else cout<<"1"<<endl;
					if(abs(pts1[i].first.X() - pts2[j].first.X()) > eps){
						pts.push_back(make_pair(pts1[i].first, Point(pts2[j].first.X(), line(pts1[i], pts2[j].first.X()))));
					}
					pts.push_back(make_pair(pts2[j].first, p));
					if(p.X() != pts2[j].second.X()){
						pts.push_back(make_pair(p, Point(pts2[j].second.X(), line(pts1[i], pts2[j].second.X()))));
					}
					pts1[i].first = Point(pts2[j].second.X(), line(pts1[i], pts2[j].second.X()));
					if(abs(pts1[i].first.X() - pts1[i].second.X()) < eps){
						i++;
					}
					j++;
				}
			}
		}
		else if(pts2[j].second.X() > pts1[i].second.X()){
			if((line(pts1[i], pts2[j].first.X()) + eps > pts2[j].first.Y()) && (pts1[i].second.Y() + eps > line(pts2[j], pts1[i].second.X()))){
				// cout << "6\n";
				pts.push_back(pts1[i]);
				pts2[j].first = Point(pts1[i].second.X(), line(pts2[j], pts1[i].second.X()));
				i++;
			}
			else if((pts2[j].first.Y() > line(pts1[i], pts2[j].first.X())) && (line(pts2[j], pts1[i].second.X()) > pts1[i].second.Y())){
				// cout << "7\n";
				if(abs(pts1[i].first.X() - pts2[j].first.X()) > eps){
					pts.push_back(make_pair(pts1[i].first, Point(pts2[j].first.X(), line(pts1[i], pts2[j].first.X()))));
				}
				pts.push_back(make_pair(pts2[j].first, Point(pts1[i].second.X(), line(pts2[j], pts1[i].second.X()))));
				pts2[j].first = Point(pts1[i].second.X(), line(pts2[j], pts1[i].second.X()));
				i++;
			}
			else if((pts2[j].first.Y() + eps > line(pts1[i], pts2[j].first.X())) && (pts1[i].second.Y() + eps > line(pts2[j], pts1[i].second.X()))){
				// cout << "8\n";
				// Point p = Intersection(pts1[i], pts2[j]);//cout<<p.X()<<" "<<p.Y()<<endl;
				Point p;
					if(abs(pts1[i].first.X() - pts1[i].second.X()) > eps && abs(pts2[j].first.X() - pts2[j].second.X()) > eps){
						p = Intersection(pts1[i], pts2[j]);//cout<<p.X()<<" "<<p.Y()<<endl;
					}
					else if(abs(pts2[j].first.X() - pts2[j].second.X()) < eps){
						p = Point(pts2[j].first.X(), line(pts1[i], pts2[j].second.X()));
					}
					else{
						p = Point(pts1[i].first.X(), line(pts2[j], pts1[i].second.X()));
					}
				// if(p.X()>=1 || p.X()<1) {;}else cout<<"1"<<endl;
				if(abs(pts1[i].first.X() - pts2[j].first.X()) > eps){
					pts.push_back(make_pair(pts1[i].first, Point(pts2[j].first.X(), line(pts1[i], pts2[j].first.X()))));
				}
				if(abs(pts2[j].first.X() - p.X()) > eps){
					pts.push_back(make_pair(pts2[j].first, p));
				}
				if(abs(p.X() - pts1[i].second.X()) > eps){
					pts.push_back(make_pair(p, pts1[i].second));
				}
				pts2[j].first = Point(pts1[i].second.X(), line(pts2[j], pts1[i].second.X()));
				i++;
			}
			else{
				// cout << "9\n";
				// Point p = Intersection(pts1[i], pts2[j]);//cout<<p.X()<<" "<<p.Y()<<endl;
				Point p;
					if(abs(pts1[i].first.X() - pts1[i].second.X()) > eps && abs(pts2[j].first.X() - pts2[j].second.X()) > eps){
						p = Intersection(pts1[i], pts2[j]);//cout<<p.X()<<" "<<p.Y()<<endl;
					}
					else if(abs(pts2[j].first.X() - pts2[j].second.X()) < eps){
						p = Point(pts2[j].first.X(), line(pts1[i], pts2[j].second.X()));
					}
					else{
						p = Point(pts1[i].first.X(), line(pts2[j], pts1[i].second.X()));
					}
				// if(p.X()>=1 || p.X()<1) {;}else cout<<"1"<<endl;
				pts.push_back(make_pair(pts1[i].first, p));
				if(abs(p.X() - pts1[i].second.X()) > eps){
					pts.push_back(make_pair(p, Point(pts1[i].second.X(), line(pts2[j], pts1[i].second.X()))));
				}
				pts2[j].first = Point(pts1[i].second.X(), line(pts2[j], pts1[i].second.X()));
				i++;
			}
		}
		else{
			// if(pts2[j].second.X() < pts1[i].first.X()){
			cout << "1\n";
			// }
			// cout << "2\n";
			// cout<<pts1.size()<<endl;
			// cout << i<<endl;
			// cout<<pts1[i].first.X() <<" "<< pts2[j].first.X()<<endl;
			// cout<<pts1[i].second.X() <<" "<< pts2[j].second.X()<<endl;
			// break;
			// i++;
		}
	}
	while(i < pts1.size()){
		// cout << "10\n";
		pts.push_back(pts1[i]);
		i++;
	}
	while(j < pts2.size()){
		// cout << "11\n";
		pts.push_back(pts2[j]);
		j++;
	}
}

void mergesort(vector<pair<Point, Point>>& pts, vector<pair<Point, Point>> posters, int l, int r){
	if(l > r) return;
	if(l == r){
		pts.push_back(posters[l]);
		return;
	}
	int mid = (l+r)/2;
	// cout << mid << endl;
	vector<pair<Point, Point>> pts1;
	vector<pair<Point, Point>> pts2;
	mergesort(pts1, posters, l, mid);
	mergesort(pts2, posters, mid+1, r);
	
	merge(pts, pts1, pts2);
	pts1.clear();
	pts2.clear();
}

int main(){
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
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

	sort(posters.begin(), posters.end(), [](const auto& p1, const auto& p2) {if(p1.first.X() == p2.first.X()) return p1.second.X() < p2.second.X(); return p1.first.X() < p2.first.X();});
	// for(int i=0;i<n;i++){
	// 	cout << posters[i].first.X() << " " << posters[i].first.Y() << " " << posters[i].second.X() << " " << posters[i].second.Y() << endl;
	// }
	// return 0;

	vector <pair<Point, Point> > pts;
	mergesort(pts, posters, 0, posters.size()-1);

	for(int i=0;i<pts.size();i++){
		// cout << "(" << pts[i].first.X() << "," << pts[i].first.Y() << ")\n";
		// cout << "(" << pts[i].second.X() << "," << pts[i].second.Y() << ")\n";
		lengthCovered += (pts[i].second.X() - pts[i].first.X());
		area += ((0.5)*(pts[i].second.X()-pts[i].first.X())*(pts[i].first.Y()+pts[i].second.Y()));
		// cout << area << endl;
	}
 
	cout << static_cast<int>(lengthCovered)<< endl;
	
	cout << static_cast<int>(area)<< endl;

	return 0;
}