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


class EllysPairs {

	public: int getDifference(vector<int> knowledge) {
		int i;
		sort(knowledge.begin(),knowledge.end());
		int min = 999999999,max = -99999;
		int size = knowledge.size();
		for(i=0;i<size/2;i++)
		{
			if(knowledge[i]+knowledge[size-1-i]<min)
				min = knowledge[i]+knowledge[size-1-i];
			if(knowledge[i]+knowledge[size-1-i]>max)
				max = knowledge[i]+knowledge[size-1-i];
		}
		return max-min;
	}

};
