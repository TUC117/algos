#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
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

// Point intersection(pair<Point, Point> line1, pair<Point, Point> line2){
//     float x11 = line1.first.X();
//     float x12 = line1.second.X();
//     float x22 = line2.second.X();
//     float x21 = line2.first.X();
//     float y11 = line1.first.Y();
//     float y12 = line1.second.Y();
//     float y22 = line2.second.Y();
//     float y21 = line2.first.Y();
//     if(abs(x12 - x11) > 1e-10 && abs(x22 - x21) > 1e-10){
//         float m1 = (y12 - y11)/(x12 - x11);
//         float m2 = (y22 - y21)/(x22 - x21);
//         float c1 = y11 - (m1 * x11);
//         float c2 = y21 - (m2 * x21);
//         if(abs(m2 - m1) > 1e-10){
//             float my_x = (c1 - c2)/(m2 - m1);
//             Point I(my_x, (m1 * my_x) + c1);
//             return I;
//         } else {
//             return Point(INT_MAX, INT_MAX);
//         }
//     } else if (abs(x12 - x11) <= 1e-10){
//         float m2 = (y22 - y21)/(x22 - x21);
//         float c2 = y21 - (m2 * x21);
//         float my_x = (y11 - c2)/(m2);
//         Point I(my_x, y11);
//         return I;
//     } else if (abs(x22 - x21) < 1e-10){
//         float m1 = (y12 - y11)/(x12 - x11);
//         float c1 = y11 - (m1 * x11);
//         float my_x = (y21 - c1)/(m1);
//         Point I(my_x, y21);
//         return I;
//     }
//     return Point(INT_MAX, INT_MAX);
// }

Point intersection(pair<Point, Point> line1, pair<Point, Point> line2){
    float x11 = line1.first.X();
    float x12 = line1.second.X();
    float x22 = line2.second.X();
    float x21 = line2.first.X();
    float y11 = line1.first.Y();
    float y12 = line1.second.Y();
    float y22 = line2.second.Y();
    float y21 = line2.first.Y();
    Point I(0, 0);
    if(abs(x12 - x11) > 1e-10 && abs(x22 - x21) > 1e-10){
        float m1 = (y12 - y11)/(x12 - x11);
        float m2 = (y22 - y21)/(x22 - x21);
        float c1 = y11 - (m1 * x11);
        float c2 = y21 - (m2 * x21);
        if(abs(m2 - m1) > 1e-10){
            float my_x = (c1 - c2)/(m2 - m1);
            I.x = my_x;
            I.y = (m1 * my_x) + c1;
            // Point I(my_x, (m1 * my_x) + c1);
            // return I;
        } else {
            I.x = INT_MAX;
            I.y = INT_MAX;
            // Point I(INT_MAX, INT_MAX);
        }
    } else if (abs(x12 - x11) <= 1e-10){
        float m2 = (y22 - y21)/(x22 - x21);
        float c2 = y21 - (m2 * x21);
        float my_x = (y11 - c2)/(m2);
        I.x = my_x;
        I.y = y11;
        // Point I(my_x, y11);
        // return I;
    } else if (abs(x22 - x21) < 1e-10){
        float m1 = (y12 - y11)/(x12 - x11);
        float c1 = y11 - (m1 * x11);
        float my_x = (y21 - c1)/(m1);
        I.x = my_x;
        I.y = y21;
        // Point I(my_x, y21);
        // return I;
    }
    if(abs(I.x - x11) < 1e-10 && abs(I.y - y11) < 1e-10){
        I.x = x11 + 1e-10;
        I.y = y11 + 1e-10;
    }
    if(abs(I.x - x21) < 1e-10 && abs(I.y - y21) < 1e-10){
        if(abs(x11 - 792) < 1e-2) cout << "yes" << endl;
        I.x = x21 + 1e-5;
        I.y = y21 + 1e-5;
        if(abs(x11 - 792) < 1e-2 && I.x > x21) cout << "yes2" << endl;
    }
    if(abs(I.x - x12) < 1e-10 && abs(I.y - y12) < 1e-10){
        I.x = x12 - 1e-10;
        I.y = y12 - 1e-10;
    }
    if(abs(I.x - x22) < 1e-10 && abs(I.y - y22) < 1e-10){
        I.x = x22 - 1e-10;
        I.y = y22 - 1e-10;
    }
    return I;
}

float height(pair<Point, Point> line, float my_x){
    float x1 = line.first.X();
    float x2 = line.second.X();
    float y1 = line.first.Y();
    float y2 = line.second.Y();
    if(abs(x2 - x1) > 1e-10){
        float m = (y2 - y1)/(x2 - x1);
        float c = y1 - (m * x1);
        return ((m * my_x) + c);
    } else if (abs(x2 - my_x) <= 1e-10){
        return y2;
    }
    return 0;
}

float single_area(pair<Point, Point> trapezium){
    float h1 = trapezium.first.Y();
    float h2 = trapezium.second.Y();
    float x1 = trapezium.first.X();
    float x2 = trapezium.second.X();
    if(abs(x2 - x1) < 1e-6) return 0;
    return (0.5 * (x2 - x1) * (h1 + h2));
}

float findArea(vector <pair<Point, Point> >& posters){
    int sz = posters.size();
    int n = (sz)/2;
    if(sz == 0) return 0;
    if(sz == 1) return single_area(posters[0]);
    vector <pair<Point, Point> > lefthalf;
    vector <pair<Point, Point> > righthalf;
    for(int k = 0; k < n; k++) lefthalf.push_back(posters[k]);
    for(int k = n; k < posters.size(); k++) righthalf.push_back(posters[k]);
    float val1 = findArea(lefthalf);
    float val2 = findArea(righthalf);
    int x11, x12, x21, x22, y11, y12, y21, y22;
    int i = 0, j = 0;
    int s1 = lefthalf.size();
    int s2 = righthalf.size();
    posters.clear();
    while(i < s1 && j < s2){
        float x11 = lefthalf[i].first.X();
        float x12 = lefthalf[i].second.X();
        float x22 = righthalf[j].second.X();
        float x21 = righthalf[j].first.X();
        float y11 = lefthalf[i].first.Y();
        float y12 = lefthalf[i].second.Y();
        float y22 = righthalf[j].second.Y();
        float y21 = righthalf[j].first.Y();
        if(x11 < x21){
            if(x12 <= x21){
                posters.push_back(lefthalf[i]);
                i++;
            } else if(x12 <= x22){
                float h_1_x21 = height(lefthalf[i], x21);
                Point I_1_2 = intersection(lefthalf[i], righthalf[j]);
                float I_1_2_x = I_1_2.X();
                if(h_1_x21 < y21){
                    posters.push_back(make_pair(lefthalf[i].first, Point(x21, h_1_x21)));
                    if(I_1_2_x > x21 && I_1_2_x < x12){
                        posters.push_back(make_pair(righthalf[j].first, I_1_2));
                        posters.push_back(make_pair(I_1_2, lefthalf[i].second));
                        righthalf[j] = make_pair(Point(x12, height(righthalf[j], x12)), righthalf[j].second);
                    }
                } else {
                    if(I_1_2_x > x21 && I_1_2_x < x12){
                        posters.push_back(make_pair(lefthalf[i].first, I_1_2));
                        righthalf[j] = make_pair(I_1_2, righthalf[j].second);
                    } else {
                        // if(abs(x11 - 792) < 1e-2) cout << "yes" << endl;
                        posters.push_back(lefthalf[i]);
                        righthalf[j] = make_pair(Point(x12, height(righthalf[j], x12)), righthalf[j].second);
                    }
                }
                i++;
            } else {
                float h_1_x21 = height(lefthalf[i], x21);
                float h_1_x22 = height(lefthalf[i], x22);
                Point I_1_2 = intersection(lefthalf[i], righthalf[j]);
                float I_1_2_x = I_1_2.X();
                if(h_1_x21 >= y21){
                    if(I_1_2_x > x21 && I_1_2_x < x22){
                        // if(abs(x11 - 60) < 1e-2) cout << "yes" << endl;
                        posters.push_back(make_pair(lefthalf[i].first, I_1_2));
                        posters.push_back(make_pair(I_1_2, righthalf[j].second));
                        lefthalf[i] = make_pair(Point(x22, h_1_x22), lefthalf[i].second);
                    }
                } else {
                    if(I_1_2_x > x21 && I_1_2_x < x22){
                        // if(abs(x11 - 60) < 1e-2) cout << "yes" << endl;
                        posters.push_back(make_pair(lefthalf[i].first, Point(x21, h_1_x21)));
                        posters.push_back(make_pair(righthalf[j].first, I_1_2));
                        lefthalf[i] = make_pair(I_1_2, lefthalf[i].second);
                    } else {
                        // if(abs(x11 - 60) < 1e-2) cout << "yes" << endl;
                        posters.push_back(make_pair(lefthalf[i].first, Point(x21, h_1_x21)));
                        posters.push_back(righthalf[j]);
                        lefthalf[i] = make_pair(Point(x22, h_1_x22), lefthalf[i].second);
                    }
                }
                j++;
            }
        } else {
            if(x22 <= x11){
                posters.push_back(righthalf[j]);
                j++;
            } else if(x22 <= x12){
                float h_2_x11 = height(righthalf[j], x11);
                Point I_1_2 = intersection(lefthalf[i], righthalf[j]);
                float I_1_2_x = I_1_2.X();
                if(h_2_x11 < y11){
                    posters.push_back(make_pair(righthalf[j].first, Point(x11, h_2_x11)));
                    if(I_1_2_x > x11 && I_1_2_x < x22){
                        posters.push_back(make_pair(lefthalf[i].first, I_1_2));
                        posters.push_back(make_pair(I_1_2, righthalf[j].second));
                        lefthalf[i] = make_pair(Point(x22, height(lefthalf[i], x22)), lefthalf[i].second);
                    }
                } else {
                    if(I_1_2_x > x11 && I_1_2_x < x22){
                        posters.push_back(make_pair(righthalf[j].first, I_1_2));
                        lefthalf[i] = make_pair(I_1_2, lefthalf[i].second);
                    } else {
                        posters.push_back(righthalf[j]);
                        lefthalf[i] = make_pair(Point(x22, height(lefthalf[i], x22)), lefthalf[i].second);
                    }
                }
                j++;
            } else {
                float h_2_x11 = height(righthalf[j], x11);
                float h_2_x12 = height(righthalf[j], x12);
                Point I_1_2 = intersection(lefthalf[i], righthalf[j]);
                float I_1_2_x = I_1_2.X();
                if(h_2_x11 >= y11){
                    if(I_1_2_x > x11 && I_1_2_x < x12){
                        // if(abs(x21 - 60) < 1e-2) cout << "yes2" << endl;
                        posters.push_back(make_pair(righthalf[j].first, I_1_2));
                        posters.push_back(make_pair(I_1_2, lefthalf[i].second));
                        righthalf[j] = make_pair(Point(x12, h_2_x12), righthalf[j].second);
                    }
                } else {
                    if(I_1_2_x > x11 && I_1_2_x < x12){
                        // if(abs(x21 - 60) < 1e-2) cout << "yes2" << endl;
                        posters.push_back(make_pair(righthalf[j].first, Point(x11, h_2_x11)));
                        posters.push_back(make_pair(lefthalf[i].first, I_1_2));
                        righthalf[j] = make_pair(I_1_2, righthalf[j].second);
                    } else {
                        // if(abs(x21 - 60) < 1e-2) cout << "yes2" << endl;
                        posters.push_back(make_pair(righthalf[j].first, Point(x11, h_2_x11)));
                        posters.push_back(lefthalf[i]);
                        righthalf[j] = make_pair(Point(x12, h_2_x12), righthalf[j].second);
                    }
                }
                i++;
            }
        }
        // else if(x11 > x21){
        //     posters.push_back(righthalf[j]);
        //     j++;
        // } else {
        //     x12 = lefthalf[i].second.X();
        //     x22 = righthalf[j].second.X();
        //     if(x12 < x22){
        //         posters.push_back(lefthalf[i]);
        //         i++;
        //     } else {
        //         posters.push_back(righthalf[j]);
        //         j++;
        //     }
        // }
    }
    while(i < s1){
        posters.push_back(lefthalf[i]);
        i++;
    }
    while(j < s2){
        posters.push_back(righthalf[j]);
        j++;
    }
    float sum = 0;
    float temp = 0;
    for(int l = 0; l < posters.size(); l++){
        temp = single_area(posters[l]);
        // if(temp > 1e6)
        // cout << temp << endl;
        sum += temp;
    }
    return sum;
}

void sort_starting_point(vector <pair<Point, Point> >& posters){
    int sz = posters.size();
    int n = (sz)/2;
    if(sz == 0 || sz == 1) return;
    vector <pair<Point, Point> > lefthalf;
    vector <pair<Point, Point> > righthalf;
    for(int k = 0; k < n; k++) lefthalf.push_back(posters[k]);
    for(int k = n; k < posters.size(); k++) righthalf.push_back(posters[k]);
    sort_starting_point(lefthalf);
    sort_starting_point(righthalf);
    int x11, x12, x21, x22;
    int i = 0, j = 0;
    int s1 = lefthalf.size();
    int s2 = righthalf.size();
    posters.clear();
    while(i < s1 && j < s2){
        x11 = lefthalf[i].first.X();
        x21 = righthalf[j].first.X();
        if(x11 < x21){
            posters.push_back(lefthalf[i]);
            i++;
        } else if(x11 > x21){
            posters.push_back(righthalf[j]);
            j++;
        } else {
            x12 = lefthalf[i].second.X();
            x22 = righthalf[j].second.X();
            if(x12 < x22){
                posters.push_back(lefthalf[i]);
                i++;
            } else {
                posters.push_back(righthalf[j]);
                j++;
            }
        }
    }
    while(i < s1){
        posters.push_back(lefthalf[i]);
        i++;
    }
    while(j < s2){
        posters.push_back(righthalf[j]);
        j++;
    }
    return;
}

float findLength(vector <pair<Point, Point> >& posters){
    int sz = posters.size();
    if(sz == 0) return 0;
    if(sz == 1) return abs(posters[0].second.X()-posters[0].first.X());
    int final_length = 0;
    float x11, x12, x21, x22;
    sort_starting_point(posters);
    vector <pair<Point, Point> > temp_posters;
    for(int k = 0; k < sz; k++) temp_posters.push_back(posters[k]);
    int i = 0, j = 1;
    while(i < sz && j < sz){
        x11 = temp_posters[i].first.X();
        x12 = temp_posters[i].second.X();
        x21 = temp_posters[j].first.X();
        x22 = temp_posters[j].second.X();
        if(x12 <= x21){
            final_length += (x12 - x11);
            // cout << "1 - " << x12 << " - " << x11 << endl;
            i = j;
            j++;
            // i++;
        } else if(x12 <= x22){
            final_length += (x21 - x11);
            // cout << "2 - " << x21 << " - " << x11 << endl;
            i = j;
            j++;
            // i++;
        } else {
            j++;
        }
    }
    if(i < sz){
        x11 = temp_posters[i].first.X();
        x12 = temp_posters[i].second.X();
        final_length += (x12- x11);
        // cout << "3 - " << i << " " << j << " " << x22 << " - " << x21 << endl;
    }
    // else if(j < sz){
    //     final_length += (x22 - x12);
    //     if(sz == 100){
    //         cout << "4 - " << x22 << " - " << x12 << endl;
    //     }
    // }
    return final_length;
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

    lengthCovered = findLength(posters);
 
	cout << static_cast<int>(lengthCovered)<< endl;
	
    area = findArea(posters);
    // cout << area << endl;
	cout << static_cast<int>(area)<< endl;

    float x1, x2, y1;

    // for(int k = 0; k < posters.size(); k++){
    //     x1 = posters[k].first.X();
    //     y1 = posters[k].first.Y();
    //     // cout << x1 << " " << y1 << endl;
    //     // x2 = posters[k+1].first.X();
    //     if(x2 < x1){
    //         cout << x1 << " " << y1 << endl;
    //     }
    // }
	return 0;
}