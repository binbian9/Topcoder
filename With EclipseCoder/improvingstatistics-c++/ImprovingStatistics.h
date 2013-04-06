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

class ImprovingStatistics {

	public: int howManyGames(int played, int won) {
		long long i;
		if(played==won)
			return -1;
		for(i=1;i<2000000000;i++)
		{
			double a,b;
			a=((won+i+0.0)/(played+i))*100;
			b = ((won+0.0)/(played))*100;
			int c,d;
			c = (int)a;
			d = (int)b;
			if(c-d==1)
				break;
		}
		return i;
	}

};
