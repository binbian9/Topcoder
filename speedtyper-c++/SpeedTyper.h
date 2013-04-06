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

class SpeedTyper {

	public: string lettersToPractice(string letters, vector<int> times) {
		int i,size;
		int sum=0;
		size = letters.length();
		sum = times[0];
		string ans="";
		double avg=0.0;
		for(i=1;i<size;i++)
		{
			sum+=times[i]-times[i-1];
		}
		avg = (sum+0.0)/size;
		if(times[0]>avg)
		{
			ans=letters[0];
		}
		for(i=1;i<size;i++)
		{
			if(times[i]-times[i-1]>avg)
				ans+=letters[i];
		}
		return ans;
	}

};
