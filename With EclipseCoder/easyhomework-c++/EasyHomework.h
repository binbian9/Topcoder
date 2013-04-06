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

class EasyHomework {

	public: string determineSign(vector<int> A) {
		int i,zero=0,counter=0;
		int size = A.size();
		for(i=0;i<size;i++)
		{
			if(A[i]<0)
				counter++;
			if(A[i]==0)
				zero++;
		}
		if(zero)
			return "ZERO";
		if(counter%2==0)
			return "POSITIVE";
		else
			return "NEGATIVE";

	}

};
