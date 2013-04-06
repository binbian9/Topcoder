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

class NextOrPrev {

	public: int getMinimum(int nextCost, int prevCost, string start, string goal) {

		int i,j,sum=0;
		int size = start.size();
		for(i=0;i<size;i++)
			for(j=i+1;j<size;j++)
				if((start[i]<start[j] && goal[i]>goal[j])||(start[i]>start[j]&&goal[i]<goal[j]))
					return -1;
		for(i=0;i<size;i++)
			if(start[i]<goal[i])
				sum+=(goal[i]-start[i])*nextCost;
			else
				sum+=(start[i]-goal[i])*prevCost;
		return sum;
};
