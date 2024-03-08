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

#define DEBUG

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

vec(pp) mymerge(vec(pp) &left, vec(pp) &right){
	vec(pp) res;
	ll li=0, ri = 0;
	
	#ifdef DEBUG
    // out("i am in mymerge");
	#endif

	while(li<left.size() && ri<right.size()){
		// If intersects
		// Base cases
		// if(fx(left[]))
		#ifdef DEBUG
		out("entered main loop");
		#endif

		if((fx(left[li]) <= fx(right[ri]) && sx(left[li]) > fx(right[ri])) ){
			// x-axis is completely inside 
				#ifdef DEBUG
				out("left < right");
				#endif
			float h1 = (fx(right[ri])-fx(left[li]))*left[li].second + (fy(left[li]) - left[li].second*fx(left[li]));
			float h2 = fy(right[ri]);
			if(sx(right[ri]) <=sx(left[li])){
				#ifdef DEBUG
				out("one is completely inside other");
				#endif
			
				// h1 = m1 * modx + y1-m1*x
				bool flag = isintersecting(left[li], right[ri]);
				if(flag){
					#ifdef DEBUG
					out("Intersecting left < right");
					#endif
									
					// intersecting we need to update both left and right
					updateintersection(left[li], right[ri],1,h1,h2);
					pp temp;
					setfx(temp,fx(left[li]));
					setfy(temp,fy(left[li]));
					setsx(temp,fx(right[ri]));
					setsy(temp,fy(right[ri]));
					res.pb(temp);
					// update left
					setfx(left[li],sx(right[ri]));
					// setfy(a,);
					setfy(left[li], h1+left[li].second*(sx(right[ri])-fx(right[ri])));
					ri++;
				}
				else{
					#ifdef DEBUG
					out("NOT Intersecting left < right");
					#endif

					// not intersecting just delete one
					if(h1>h2){
						#ifdef DEBUG
						out("NOT Intersecting left < right and h1 > h2");
						#endif						

						res.pb(left[li]);
						li++;
						ri++;
					}
					else if(h1<h2){
						#ifdef DEBUG
						out("NOT Intersecting left < right and h1 < h2");
						#endif						
												
						pp temp;
						setfx(temp,fx(left[li]));
						setfy(temp,fy(left[li]));
						setsx(temp,fx(right[ri]));
						setsy(temp,h1);
						res.pb(temp);
						res.pb(right[ri]);
						ri++;
						setfx(left[li],sx(right[ri]));
						setfy(left[li], h1+left[li].second*(sx(right[ri])-fx(right[ri])));
					}
				}
			}
			// x-axis is partially inside
			else{
				#ifdef DEBUG
				out("one is partailly inside other left < right");
				#endif
								
				bool flag = isintersecting(left[li], right[ri]);
				// out(flag);
				if(flag){
					#ifdef DEBUG
					out("one is partailly inside other -  left < right - INtersecting");
					#endif					
					if(h1<h2){
						#ifdef DEBUG
						out("one is partailly inside other -  left < right - INtersecting - h1 < h2");
						#endif											
						pp temp;
						setfx(temp,fx(left[li]));
						setfy(temp,fy(left[li]));
						setsx(temp,fx(right[ri]));
						setsy(temp,h1);
						res.pb(temp);
						updateintersection(left[li],right[ri],0,h1,h2);
						setfx(temp,fx(right[ri]));
						setfy(temp,fy(right[ri]));
						setsx(temp,fx(left[li]));
						setsy(temp,fy(left[li]));
						res.pb(temp);
						// update right
						setfy(right[ri], h2+right[ri].second*(fx(right[ri])-sx(left[li])));
						setfx(right[ri], sx(left[li]));
						li++;
					}
					if(h1>=h2){
						#ifdef DEBUG
						out("one is partailly inside other -  left < right - INtersecting - h1 >= h2");
						#endif																	
						updateintersection(left[li],right[ri],0,h1,h2);
						li++;
					}
				}
				else{
					#ifdef DEBUG
					out("one is partailly inside other -  left < right - NOT intersecting");
					#endif																
					// if not intersecting
					if(h1>h2){
						#ifdef DEBUG
						out("one is partailly inside other -  left < right - NOT intersecting - h1 > h2");
						#endif																		
						// update right and push left
						res.pb(left[li]);
						setfx(right[ri],sx(left[li]));
						setfy(right[ri],h2 + right[ri].second*(sx(left[li])-fx(right[ri])));
						li++;
					}					
					else if(h1<=h2){
						#ifdef DEBUG
						out("one is partailly inside other -  left < right - NOT intersecting - h1 <= h2");
						#endif																					
						// update left and push
						setsx(left[li],fx(right[ri]));
						setsy(left[li],h1);
						res.pb(left[li]);
						li++;
					}					
				}
				
			}	
		}

		else if(fx(right[ri]) < fx(left[li]) && fx(left[li]) < sx(right[ri]) && sx(right[ri])<sx(left[li])){
			// x-axis is completely inside 
			#ifdef DEBUG
			out("right < left");
			#endif

			float h1 = fy(left[li]);
			float h2 = fy(right[ri]);
			// x-axis is partially inside
			// else{
				#ifdef DEBUG
				out("one is partailly inside other - right < left");
				#endif
								
				bool flag = isintersecting(left[li], right[ri]);
				if(flag){
					#ifdef DEBUG
					out("one is partailly inside other - right < left - INtersecting");
					#endif					
					if(h1<h2){
						#ifdef DEBUG
						out("one is partailly inside other - right < left - INtersecting - h1 < h2");
						#endif											
						float X = (fy(left[li]) - fy(right[ri]) + right[ri].second*fx(right[ri]) - left[li].second*fx(left[li]))/(right[ri].second - left[li].second);
						float Y = left[li].second*(X-fx(left[li])) + fy(left[li]);	
						// update right and push lol
						setsx(right[ri],X);
						setsy(right[ri],Y);
						res.pb(right[ri]);
						ri++;
						//update left
						setfx(left[li], X);
						setfy(left[li], Y);
	
					}
					if(h1>=h2){
						#ifdef DEBUG
						out("one is partailly inside other - INtersecting - h1 >= h2");
						#endif																	
						float X = (fy(left[li]) - fy(right[ri]) + right[ri].second*fx(right[ri]) - left[li].second*fx(left[li]))/(right[ri].second - left[li].second);
						float Y = left[li].second*(X-fx(left[li])) + fy(left[li]);							
						pp temp;
						setfx(temp, fx(right[ri]));
						setfy(temp, fy(right[ri]));
						float ee = (fx(left[li])-fx(right[ri]))*right[ri].second + fy(right[ri]);
						setsx(temp, fx(left[li]));
						setsy(temp, ee);
						temp.second = right[ri].second;
						res.pb(temp);
						setfx(temp, fx(left[li]));
						setfy(temp, fy(left[li]));
						setsx(temp, X);
						setsy(temp, Y);
						temp.second = left[li].second;
						res.pb(temp);
						setsx(right[ri], X);
						setsy(right[ri], Y);
						res.pb(right[ri]);
						
						ee = (sx(right[ri]) - fx(left[li]))*left[li].second+fy(left[li]);
						// update left
						setfx(left[li], sx(right[ri]));
						setsy(left[li], ee);
						ri++;
					}
				}
				
				else{
					#ifdef DEBUG
					out("one is partailly inside other - NOT intersecting");
					#endif																
					// if not intersecting
					if(h1>h2){
						#ifdef DEBUG
						out("one is partailly inside other - NOT intersecting - h1 > h2");
						#endif																		
						// update right and push left
						// update h2 wala right and ri++
						float ee = (fx(left[li])-fx(right[ri]))*right[ri].second + fy(right[ri]);
						setsx(right[ri], fx(left[li]));
						setfy(right[ri], ee);
						res.pb(right[ri]);
						ri++;
					}					
					else if(h1<=h2){
						#ifdef DEBUG
						out("one is partailly inside other - NOT intersecting - h1 <= h2");
						#endif																					
						// update left and push
						// update left
						float ee = (sx(right[ri])-fx(left[li]))*left[li].second + fy(left[li]);
						res.pb(right[ri]);
						setfx(left[li], sx(right[ri]));
						setsy(left[li], ee);
						ri++;

					}					
				}
				
			// }	
		}

		if(sx(left[li]) < fx(right[ri])){
			#ifdef DEBUG
			out("NOT IN MAIN CASE 1");
			#endif				
			res.pb(left[li]);
			li++;
		}
		if(sx(right[ri]) < sx(left[li])){
			#ifdef DEBUG
			out("NOT IN MAIN CASE 2");
			#endif							
			res.pb(right[li]);
			li++;
		}

	} 

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

int main(){
	pp a, b;
	int a,b,c,d;
	float s1, s2;
	
}