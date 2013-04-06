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

class RandomSwaps {

	public: double getProbability(int arrayLength, int swapCount, int a, int b) {
		double as[1001],ans[1001];
		int i;
		if(a==b)
		{
			as[0]=1.0;
			ans[0]=0.0;
		}
		else
		{
			as[0]=0.0;
			ans[0]=1.0;
		}

		for(i=1;i<=swapCount;i++)
		{
			double P_WR = (2.0)/(arrayLength*(arrayLength-1)); // w to r
			double P_RR = (arrayLength-2.0)/arrayLength; //r to w
			as[i]=P_RR*as[i-1] + P_WR*ans[i-1];
			ans[i]=1-as[i];
			//ans[i]=(temp2)*as[i-1] + (1.0-temp2)*ans[i-1];
		}
			return as[swapCount];
	}

};
