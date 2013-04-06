#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define eps (le-7)
#define INF (le60)
#define MAX (1<<30)
#define MIN (-MAX)

#define pb push_back

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()
#define gcd(a,b) __gcd(a,b)
#define EQ(a,b) (abs(a-b) <eps)
#define sqr(a) ((a)*(a))
#define popcount(n) __builtin_popcount(n)

class CombinationLock {

	public: double degreesTurned(vector<int> combo, int size, int start) {
		int N = combo.size();
		int s = start;
		double sum = 0.0;
		int direction = 1;
		for(int i=0;i<N;i++)
		{
			sum+=(N-i)*360.0 ;
			//cout<<"i="<<i<<", (N-i)*360.0 ="<<(N-i)*360.0<<endl;
			int temp = 0;
			if(direction) //counterclock
			{
				if(combo[i]-s<0)
					temp = size-(s-combo[i]);
				else
					temp = combo[i]-s;
				//sum+=temp*(360.0/size)*1.0;
			}
			else //clockwise
			{
				if(combo[i]-s<0)
					temp = (s-combo[i]);
				else
					temp = size-(combo[i]-s);
				//sum+=temp*(360.0/size)*1.0;
			}
			s = combo[i];
			direction= direction^1;
			//cout<<"i="<<i<<", temp ="<<temp<<endl;
			sum+=temp*(360.0/size)*1.0;
		}
		return sum;
	}

};
