/*
	AUTHOR - TUK04
*/

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

	void setX(float xVal) { x = xVal; }
	void setY(float yVal) { y = yVal; }    
};

#define pp pair<pair<Point,Point>,double>
typedef long long ll;
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define vec(x) vector<x> 
#define fi(i,a,b) for(ll i(a);i<b;i++)
#define fd(i,a,b) for(ll i(a);i>=b;i--)
#define jui()  (ios_base:: sync_with_stdio(false),cin.tie(NULL));
#define yes() cout<<"YES"<<"\n"
#define no() cout<<"NO"<<"\n"
#define in(n) cin>>n
#define out(n) cout<<n<<"\n"
#define fx(t) t.first.first.X()
#define fy(t) t.first.first.Y()
#define sx(t) t.first.second.X()
#define sy(t) t.first.second.Y()
#define setsy(t, val) t.first.second.setY(val)
#define setfy(t, val) t.first.first.setY(val)
#define setsx(t, val) t.first.second.setX(val)
#define setfx(t, val) t.first.first.setX(val)

void dout(string s){
	#ifdef DEBUG
		out(s);
	#endif		
}

bool comparePosters(const pp& a, const pp& b) {
    return a.first.first.X() < b.first.first.X();
}

float length(vector <pp> posters){
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

bool isintersecting(pp a,pp b){
	float X = (fy(a) - fy(b) + b.second*fx(b) - a.second*fx(a))/(b.second - a.second);
	float Y = a.second*(X-fx(a)) + fy(a);
	// return ((fy(a)-fy(b))*(sy(a)-sy(b))<=0);
	return ((X >= fx(a) && X <= sx(a)) && (X >= fx(b) && X <= sx(b)));
}

void helpme(pp &a, float FX, float FY, float SX, float SY, float slope){
	setfx(a, FX);
	setfy(a, FY);
	setsx(a, SX);
	setsy(a, SY);
	a.second = slope;
}

vec(pp) mymerge(vec(pp) &left, vec(pp) &right){
	vec(pp) res;
	ll li=0, ri = 0;
	
	// #ifdef DEBUG
    // // out("i am in mymerge");
	// #endif

	while(li<left.size() && ri<right.size()){
		// cout << (fx(left[li])) << (" - ") << (fy(left[li])) << (" - ") << (sx(left[li])) << (" - ") << (sy(left[li])) << endl;
		// cout << (fx(right[ri])) << (" - ") << (fy(right[ri])) << (" - ") << (sx(right[ri])) << (" - ") << (sy(right[ri])) << endl;
		if(sx(right[ri]) <= fx(left[li])){
			dout("CASE 1");
			res.pb(right[ri]);
			// res.pb(left[li]);
			// li++;
			ri++;
		}
		else if(fx(right[ri]) >= sx(left[li])){
			dout("CASE 2");
			// res.pb(right[ri++]);
			res.pb(left[li]);
			li++;
		}
		else if(fx(right[ri]) >= fx(left[li]) && sx(right[ri]) <= sx(left[li])){
			bool flag = isintersecting(left[li], right[ri]);
			if(flag){
				float h1 = left[li].second * fx(right[ri]) + (fy(left[li]) - left[li].second*fx(left[li]));
				pp a = left[li], b =  right[ri];
				float X = (fy(a) - fy(b) + b.second*fx(b) - a.second*fx(a))/(b.second - a.second);
				float Y = a.second*(X-fx(a)) + fy(a);	
				if(h1 > fy(right[ri])){
					dout("CASE 3");
					pp temp;
					// if(fx(left[li]) > X){
					// 	cout << (fx(left[li])) << (" - ") << (fy(left[li])) << (" - ") << (sx(left[li])) << (" - ") << (sy(left[li])) << endl;
					// 	cout << (fx(right[ri])) << (" - ") << (fy(right[ri])) << (" - ") << (sx(right[ri])) << (" - ") << (sy(right[ri])) << endl;
					// }
					helpme(temp, fx(left[li]), fy(left[li]), X, Y, left[li].second);
					res.pb(temp);
					helpme(right[ri], X, Y, sx(right[ri]), sy(right[ri]), right[ri].second);
					res.pb(right[ri]);
					helpme(left[li], sx(right[ri]), left[li].second*(sx(right[ri])) + fy(left[li])-left[li].second*fx(left[li]), sx(left[li]), sy(left[li]), left[li].second);
					// res.pb(left[li]);
					ri++;
					// li++;
				}
				else if(h1 < fy(right[ri])){
					dout("CASE 4");
					pp temp;
					helpme(temp, fx(left[li]), fy(left[li]), fx(right[ri]), fx(right[ri])*left[li].second + (fy(left[li]) - left[li].second*fx(left[li])), left[li].second);
					res.pb(temp);
					helpme(right[ri], fx(right[ri]), fy(right[ri]), X, Y, right[ri].second);
					res.pb(right[ri]);
					helpme(left[li],X, Y, sx(left[li]), sy(left[li]), left[li].second);
					// res.pb(left[li]);
					// li++; 
					ri++;
				}
				else{
					if(right[ri].second > left[li].second){
						dout("CASE 5");
						pp temp;
						helpme(temp, fx(left[li]), fy(left[li]), X, Y, left[li].second);
						res.pb(temp);
						helpme(right[ri], X, Y, sx(right[ri]), sy(right[ri]), right[ri].second);
						res.pb(right[ri]);
						helpme(left[li], sx(right[ri]), left[li].second*(sx(right[ri])) + fy(left[li])-left[li].second*fx(left[li]), sx(left[li]), sy(left[li]), left[li].second);
						// res.pb(left[li]);
						ri++;
						// li++;
					}
					else{
						dout("CASE 6");
						// res.pb(left[li]);
						// li++;
						ri++;
					}
				}
			}
			else{
				// dout("HIII");
				float h1 = fx(right[ri])*left[li].second + (fy(left[li]) - left[li].second*fx(left[li]));
				if(h1>fy(right[ri])){
					dout("CASE 7");
					// res.pb(left[li]);
					// li++;
					ri++;
				}
				else 
				// if(h1<fy(right[ri]))
				{
					dout("CASE 8");
					pp temp;
					helpme(temp, fx(left[li]), fy(left[li]), fx(right[ri]), h1, left[li].second);
					res.pb(temp);
					res.pb(right[ri]);
					helpme(left[li], sx(right[ri]),sx(right[ri])*left[li].second + (fy(left[li]) -left[li].second*fx(left[li])), sx(left[li]), sy(left[li]), left[li].second);
					// res.pb(left[li]);
					// li++;
					ri++;
				}
			}	
		}
		else if(fx(left[li]) >= fx(right[ri]) && sx(left[li]) <= sx(right[ri])){
			bool flag = isintersecting(left[li], right[ri]);
			if(flag){
				float h1 = right[ri].second * fx(left[li]) + (fy(right[ri]) - right[ri].second*fx(right[ri]));
				pp a = left[li], b =  right[ri];
				float X = (fy(a) - fy(b) + b.second*fx(b) - a.second*fx(a))/(b.second - a.second);
				float Y = a.second*(X-fx(a)) + fy(a);	
				if(h1 > fy(left[li])){
					dout("CASE 10");
					pp temp;
					helpme(temp, fx(right[ri]), fy(right[ri]), X, Y, right[ri].second);
					res.pb(temp);
					helpme(left[li], X, Y, sx(left[li]), sy(left[li]), left[li].second);
					res.pb(left[li]);
					helpme(right[ri], sx(left[li]), right[ri].second*(sx(left[li])) + (fy(right[ri])-right[ri].second*fx(right[ri])), sx(right[ri]), sy(right[ri]), right[ri].second);
					// res.pb(right[ri]);
					// ri++;
					li++;
				}
				else if(h1 < fy(left[li])){
					dout("CASE 9");
					pp temp;
					helpme(temp, fx(right[ri]), fy(right[ri]), fx(left[li]), fx(left[li])*right[ri].second + (fy(right[ri]) - right[ri].second*fx(right[ri])), right[ri].second);
					res.pb(temp);
					helpme(left[li], fx(left[li]), fy(left[li]), X, Y, left[li].second);
					res.pb(left[li]);
					helpme(right[ri],X, Y, sx(right[ri]), sy(right[ri]), right[ri].second);
					// res.pb(right[ri]);
					li++; 
					// ri++;
				}
				else{
					if(right[ri].second < left[li].second){
						dout("CASE 11");
						pp temp;
						helpme(temp, fx(right[ri]), fy(right[ri]), X, Y, right[ri].second);
						res.pb(temp);
						helpme(left[li], X, Y, sx(left[li]), sy(left[li]), left[li].second);
						res.pb(left[li]);
						helpme(right[ri], sx(left[li]), right[ri].second*(sx(left[li])) + fy(right[ri])-right[ri].second*fx(right[ri]), sx(right[ri]), sy(right[ri]), right[ri].second);
						// res.pb(right[ri]);
						// ri++;
						li++;						
					}
					else{
						dout("CASE 12");
						// res.pb(right[ri]);
						li++;
						// ri++;
					}
				}
			}
			else{
				// dout("HIII");
				float h1 = fx(left[li])*right[ri].second + (fy(right[ri]) - right[ri].second*fx(right[ri]));
				
				if(h1>fy(left[li])){
					dout("CASE 14");
					// res.pb(right[ri]);
					li++;
					// ri++;
				}
				else 
				// if(h1<fy(left[li]))
				{
					dout("CASE 13");
					pp temp;
					helpme(temp, fx(right[ri]), fy(right[ri]), fx(left[li]), h1, right[ri].second);
					res.pb(temp);
					res.pb(left[li]);
					helpme(right[ri], sx(left[li]),sx(left[li])*right[ri].second + (fy(right[ri]) -right[ri].second*fx(right[ri])), sx(right[ri]), sy(right[ri]), right[ri].second);
					// res.pb(right[ri]);
					li++;
					// ri++;
				}
			}	
		}
		else if(fx(right[ri]) > fx(left[li]) && fx(right[ri]) < sx(left[li]) && sx(right[ri]) > sx(left[li])){
			bool flag = isintersecting(left[li], right[ri]);
			float h1 = fx(right[ri])*left[li].second + (fy(left[li]) - left[li].second*fx(left[li]));
			if(flag){
				pp a = left[li], b =  right[ri];
				float X = (fy(a) - fy(b) + b.second*fx(b) - a.second*fx(a))/(b.second - a.second);
				float Y = a.second*(X-fx(a)) + fy(a);					
				if(h1 > fy(right[ri])){
					dout("CASE 15");
					helpme(left[li], fx(left[li]), fy(left[li]), X, Y, left[li].second);
					res.pb(left[li]);
					helpme(right[ri],X, Y, sx(right[ri]), sy(right[ri]), right[ri].second);
					// res.pb(right[ri]);
					li++;
					// ri++;
				}
				else if(h1 < fy(right[ri])){
					dout("CASE 16");
					pp temp1;
					helpme(temp1,fx(left[li]), fy(left[li]), fx(right[ri]), fx(right[ri])*left[li].second + (fy(left[li]) -left[li].second*fx(left[li])), left[li].second);
					res.pb(temp1);
					helpme(temp1,fx(right[ri]), fy(right[ri]), X, Y, right[ri].second);
					res.pb(temp1);
					helpme(left[li],X,Y,sx(left[li]), sy(left[li]),left[li].second);
					res.pb(left[li]);
					helpme(right[ri],sx(left[li]), sx(left[li])*right[ri].second + (fy(right[ri]) - right[ri].second*fx(right[ri])),sx(right[ri]),sy(right[ri]),right[ri].second);
					// res.pb(right[ri]);
					// ri++;
					li++;
				}
				else{
					if(left[li].second >= right[ri].second){
						dout("CASE 17");
						res.pb(left[li]);
						helpme(right[ri],sx(left[li]), sx(left[li])*right[ri].second + (fy(right[ri]) - right[ri].second*fx(right[ri])), sx(right[ri]), sy(right[ri]), right[ri].second);
						// res.pb(right[ri]);
						li++; 
						// ri++;
					}
					else{
						dout("CASE 18");
						helpme(left[li],fx(left[li]), fy(left[li]), X, Y, left[li].second);
						res.pb(left[li]);
						// res.pb(right[ri]);
						li++; 
						// ri++;
					}
				}
			}
			else{
				if(h1>fy(right[ri])){
					dout("CASE 19");
					res.pb(left[li]);
					helpme(right[ri], sx(left[li]), sx(left[li])*right[ri].second + (fy(right[ri]) -right[ri].second*fx(right[ri])), sx(right[ri]), sy(right[ri]), right[ri].second);
					// res.pb(right[ri]);
					li++; 
					// ri++;
				}
				else{
					dout("CASE 20");
					helpme(left[li],fx(left[li]),fy(left[li]),fx(right[ri]),fx(right[ri])*left[li].second + (fy(left[li]) - left[li].second*fx(left[li])), left[li].second);
					res.pb(left[li]);
					// res.pb(right[ri]);
					li++;
					// ri++;
				}
			}
		}
		// else if(fx(left[li]) > fx(right[ri]) && fx(left[li]) < sx(right[ri]) && sx(left[li]) > sx(right[ri])){
		else{
			bool flag = isintersecting(left[li], right[ri]);
			float h1 = fx(left[li])*right[ri].second + (fy(right[ri]) - right[ri].second*fx(right[ri]));
			if(flag){
				pp a = left[li], b =  right[ri];
				float X = (fy(a) - fy(b) + b.second*fx(b) - a.second*fx(a))/(b.second - a.second);
				float Y = a.second*(X-fx(a)) + fy(a);					
				if(h1 > fy(left[li])){
					dout("CASE 21");
					helpme(right[ri], fx(right[ri]), fy(right[ri]), X, Y, right[ri].second);
					res.pb(right[ri]);
					helpme(left[li],X, Y, sx(left[li]), sy(left[li]), left[li].second);
					// res.pb(left[li]);
					// li++;
					ri++;
				}
				else if(h1 < fy(left[li])){
					dout("CASE 22");
					pp temp1;
					helpme(temp1,fx(right[ri]), fy(right[ri]), fx(left[li]), fx(left[li])*right[ri].second + (fy(right[ri]) -right[ri].second*fx(right[ri])), right[ri].second);
					res.pb(temp1);
					helpme(temp1,fx(left[li]), fy(left[li]), X, Y, left[li].second);
					res.pb(temp1);
					helpme(right[ri],X,Y,sx(right[ri]), sy(right[ri]),right[ri].second);
					res.pb(right[ri]);
					helpme(left[li],sx(right[ri]), sx(right[ri])*left[li].second + (fy(left[li]) - left[li].second*fx(left[li])),sx(left[li]),sy(left[li]),left[li].second);
					// res.pb(left[li]);
					ri++;
					// li++;
				}
				else{
					if(left[li].second <= right[ri].second){
						dout("CASE 23");
						res.pb(right[ri]);
						helpme(left[li],sx(right[ri]), sx(right[ri])*left[li].second + (fy(left[li]) - left[li].second*fx(left[li])), sx(left[li]), sy(left[li]), left[li].second);
						// res.pb(left[li]);
						// li++; 
						ri++;
					}
					else{
						dout("CASE 24");
						helpme(right[ri],fx(right[ri]), fy(right[ri]), X, Y, right[ri].second);
						// res.pb(left[li]);
						res.pb(right[ri]);
						// li++; 
						ri++;
					}
				}
			}
			else{
				if(h1>fy(left[li])){
					dout("CASE 25");
					res.pb(right[ri]);
					helpme(left[li], sx(right[ri]), sx(right[ri])*left[li].second + (fy(left[li]) -left[li].second*fx(left[li])), sx(left[li]), sy(left[li]), left[li].second);
					// res.pb(left[li]);
					// li++; 
					ri++;
				}
				else{
					dout("CASE 26");
					helpme(right[ri],fx(right[ri]),fy(right[ri]),fx(left[li]),fx(left[li])*right[ri].second + (fy(right[ri]) - right[ri].second*fx(right[ri])), right[ri].second);
					// res.pb(left[li]);
					res.pb(right[ri]);
					// li++;
					ri++;
				}
			}
		}

	} 
    // dout("hii");
	while(li<left.size()){
			#ifdef DEBUG
			out("Left is left");
			#endif			
		res.pb(left[li]);
		li++;
	}
	while(ri<right.size()){
			#ifdef DEBUG
			out("Right is left");
			#endif					
		res.pb(right[ri]);
		ri++;
	}
	return res;
}


vec(pp)merger_sort(vec(pp)posters){

	#ifdef DEBUG
    	// out("i am in merger_sort");
	#endif

	if(posters.size()==1) return posters;
	vec(pp) left(posters.begin(), posters.begin()+posters.size()/2);
	vec(pp) right(posters.begin()+posters.size()/2, posters.end());
	left = merger_sort(left);
	right = merger_sort(right);
	return mymerge(left,right);
}

float calarea(vec(pp) data){
	float area = 0;
	// int n = 0;
	for(auto i : data){
		area += (sx(i)-fx(i))*(fy(i) + sy(i))*0.5;
	}
	// cout << sx(i)-fx(i) << endl;
	// cout << data.size() << endl;
	return area;
}

int main(){
	   /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
	jui();
	int n;
	in(n);
	float a,b,c,d;

	vec(pp) posters; 

	for(int i=0; i<n; i++){
		in(a>>b>>c>>d);
		float slope;
		if(c!=a) slope = (float)(d-b)/(c-a);
		else slope = 1e18;
		posters.pb(mp(mp(Point(a,b), Point(c,d)),slope));
	}

	float lengthCovered =0; 
	float area =0;
	// Sorting the posters in increasing order of their c
	
	// for(int i=0;i<n;i++){
	// 	cout<<posters[i].first.first.X()<<" "<<posters[i].first.first.Y()<<" "<<posters[i].first.second.X()<<" "<<posters[i].first.second.Y()<<" "<<posters[i].second<<endl;
	// }
	// #ifdef DEBUG
	// #endif
	vec(pp) posters1 = posters;
	sort(posters.begin(), posters.end(), comparePosters);
	lengthCovered = length(posters);
	cout << static_cast<int>(lengthCovered)<< endl;


	vec(pp) data = merger_sort(posters);
	area = calarea(data);
	for(auto i : data){
		// out(fx(i)<<" "<<fy(i)<<" "<<sx(i)<<" "<<sy(i));
	}
	// cout<<areaOfTwoTrapiziums(posters[0],posters[1])<<endl;
	cout << static_cast<int>(area)<< endl;

	return 0; 
}
