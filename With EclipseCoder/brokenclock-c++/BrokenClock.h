#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

class BrokenClock {

	public: int fewestClicks(string clockTime, string currentTime) {
		int x,y,z,w,aa,bb,a,b,ans=0,mm,m;
		w = clockTime[0]-'0';
		x = clockTime[1]-'0';
		y = clockTime[3]-'0';
		z = clockTime[4]-'0';
		aa = w*10+x;
		bb = y*10+z;
		mm = aa*60+bb;
		w = currentTime[0]-'0';
		x = currentTime[1]-'0';
		y = currentTime[3]-'0';
		z = currentTime[4]-'0';
		a = w*10+x;
		b = y*10+z;
		m = a*60+b;

		if(m>=mm)
		{
			cout<<mm<<" "<<m<<endl;
			ans=(m-mm)/61+(m-mm)%61;
		}
		else
		{
			cout<<mm<<" "<<m<<endl;
			if(aa==a)
				ans=(((b+60-bb)/61+(b+60-bb)%61));
			else
				ans=(((m-mm+24*60)/61+(m-mm+24*60)%61));
		}
		return ans;
	}

};
