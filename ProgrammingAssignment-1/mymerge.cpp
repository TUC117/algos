		if(li < left.size() && ri < right.size() && (fx(right[ri]) <= fx(left[li]) && sx(right[ri]) >= fx(left[li])) ){
			// x-axis is completely inside 
				#ifdef DEBUG
				out("left < right");
				#endif
			// float h1 = (fx(right[ri])-fx(left[li]))*left[li].second + (fy(left[li]) - left[li].second*fx(left[li]));
			float h1 = fy(left[li]);
			float h2 = right[ri].second*fx(left[li] + (fy(left[li]) - right[ri].second*(fx(left[li]) -fx(right[ri]))));
			if(sx(left[li]) <= sx(right[ri])){	// CHECKED THIS PART 
				
				#ifdef DEBUG
				out("one is completely inside other");
				#endif
			
				// h1 = m1 * modx + y1-m1*x
				bool flag = isintersecting(left[li], right[ri]);
				if(flag){
					#ifdef DEBUG
					out("one is completely inside other - Intersecting left < right");
					#endif
									
					// intersecting we need to update both left and right
					// updateintersection(left[li], right[ri],1,h1,h2);
					pp a = left[li], b =  right[ri];
					float X = (fy(a) - fy(b) + b.second*fx(b) - a.second*fx(a))/(b.second - a.second);
					float Y = a.second*(X-fx(a)) + fy(a);		
					if(h1>h2){
						setfx(a,fx(right[ri]));
						setfy(a,fy(right[ri]));
						setsx(a,fx(left[li]));
						setsy(a,);
						a.second = right[ri].second;
						#ifdef DEBUG
						out(fx(a)<<" "<<fy(a)<<" "<<sx(a)<<" "<<sy(a));
						#endif
						res.pb(a);

						setfx(left[li],X);
						setfy(left[li],Y);
						#ifdef DEBUG
						out(fx(right[ri])<<" "<<fy(right[ri])<<" "<<sx(right[ri])<<" "<<sy(right[ri]));
						#endif						
						res.pb(left[li]);

						setfx(right[ri],sx(left[li]));
						setfy(right[ri],right[ri].second * sx(left[li]) + (-1*sx(right[ri])*right[ri].second + sy(right[ri])));
						res.pb(right[ri]);
						li++;
						ri++;
					}
					else if(h1<h2){
						setfx(a,fx(right[ri]));
						setfy(a,fy(right[ri]));
						setsx(a,fx(left[li]));
						setsy(a,fy(right[ri]) + (fx(left[li])-fx(right[ri]))*right[ri].second );
						a.second = right[ri].second;
						#ifdef DEBUG
						out(fx(a)<<" "<<fy(a)<<" "<<sx(a)<<" "<<sy(a));
						#endif						
						res.pb(a);

						setsx(left[li],X);
						setsy(left[li],Y);
						#ifdef DEBUG
						out(fx(right[ri])<<" "<<fy(right[ri])<<" "<<sx(right[ri])<<" "<<sy(right[ri]));
						#endif						
						res.pb(left[li]);
						setfx(right[ri],X);
						setfy(right[ti],Y);
						res.pb(right[ri]);
						li++;
						ri++;						
					}
					else{
						if(left[li].second > right[ri].second){
							res.pb(right[ri]);
							li++;
							ri++;
						}
						else{
							setfx(a,fx(right[ri]));
							setfy(a,fy(right[ri]));
							setsx(a,fx(left[li]));
							setsy(a,fy(right[ri]) + right[ri].second*(fx(left[li]) - fx(right[ri])));
							a.second = right[ri].second;
							#ifdef DEBUG
							out(fx(a)<<" "<<fy(a)<<" "<<sx(a)<<" "<<sy(a));
							#endif												
							res.pb(a);
							setsx(left[li],X);
							setsy(left[li],Y);
							#ifdef DEBUG
							out(fx(right[ri])<<" "<<fy(right[ri])<<" "<<sx(right[ri])<<" "<<sy(right[ri]));
							#endif													
							res.pb(left[li]);

							setfx(right[ri],X);
							setfy(right[ri],Y );
							res.pb(right[ri]);
							li++;
							ri++;							
						}
					}
				}
				else{
					#ifdef DEBUG
					out("one is completely inside other - NOT Intersecting left < right");
					#endif

					// not intersecting just delete one
					if(h1>h2){
						#ifdef DEBUG
						out("NOT Intersecting left < right and h1 > h2");
						#endif						

						// res.pb(left[li]);
						res.pb(left[li]);
						li++;
						// li++;
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
						temp.second = left[li].second;
						res.pb(temp);

						res.pb(right[ri]);

						setfx(left[li],sx(right[ri]));
						setfy(left[li], h1+left[li].second*(sx(right[ri])-fx(right[ri])));
						res.pb(left[li]);
						li++;
						ri++;
					}
				}
			}
			// x-axis is partially inside
			else{  // CHECKED THIS PART
				#ifdef DEBUG
				out("one is partailly inside other left < right");
				#endif
								
				bool flag = isintersecting(left[li], right[ri]);
				// out(flag);
				if(flag){

					#ifdef DEBUG
					out("one is partailly inside other -  left < right - INtersecting");
					#endif

					pp a=left[li], b = right[ri];
					float X = (fy(a) - fy(b) + b.second*fx(b) - a.second*fx(a))/(b.second - a.second);
					float Y = a.second*(X-fx(a)) + fy(a);						
											
					if(h1>h2){
						#ifdef DEBUG
						out("one is partailly inside other -  left < right - INtersecting - h1 > h2");
						#endif
						// Update left and push that' sit
						setsx(left[li], X);
						setsy(left[li], Y);
						res.pb(left[li]);
						li++;

						setfx(right[ri], X);
						setfy(right[ri], Y);
						res.pb(right[ri]);
						ri++;
					}
					else if(h1<h2){
						#ifdef DEBUG
						out("one is partailly inside other -  left < right - INtersecting - h1 < h2");
						#endif																	
						// add two parts and update two parts
						setfx(a, fx(left[li]));
						setfy(a, fy(left[li]));
						setsx(a, fx(right[ri]));
						setsy(a, h1);
						a.second = left[li].second;
						res.pb(a);

						setfx(a, fx(right[ri]));
						setfy(a, fy(right[ri]));
						setsx(a, X);
						setsy(a, Y);
						a.second = right[ri].second;
						res.pb(a);

						// update left
						setfx(left[li], X);
						setfy(left[li], Y);
						

						// update right
						setfx(right[ri],sx(left[li]));
						setfy(right[ri],Y + right[ri].second*(sx(left[li])-X));
						res.pb(right[ri]);
						ri++;

						// push left
						res.pb(left[li]);
						li++;

					}
					else{
						#ifdef DEBUG
						out("one is partailly inside other -  left < right - INtersecting - h1 = h2");
						#endif		
						if(left[li].second >= right[ri].second){
							res.pb(left[li]);
							setfx(right[ri], sx(left[li]));
							setfy(right[ri], right[ri].second*sx(left[li])+(fy(right[ri]) - right[ri].second*fx(right[ri])));
							res.pb(right[ri]);
							ri++;
							li++;
						}
						else{
							setsx(left[li], X);
							setsy(left[li], Y);
							res.pb(left[li]);
							li++;
							res.pb(right[ri]);
							ri++;
						}
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
						res.pb(right[ri]);
						ri++;
						li++;
					}					
					else if(h1<h2){
						#ifdef DEBUG
						out("one is partailly inside other -  left < right - NOT intersecting - h1 <= h2");
						#endif																					
						// update left and push
						setsx(left[li],fx(right[ri]));
						setsy(left[li],h1);
						res.pb(left[li]);
						res.pb(right[ri]);
						ri++;
						li++;
					}					
				}
				
			}	
		}

