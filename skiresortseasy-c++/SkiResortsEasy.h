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

class SkiResortsEasy {

	public: int minCost(vector<int> altitude) {
		int size = altitude.size();
		int sum = 0;
		int last = altitude[0];
		for(int i=1;i<size;i++)
		{
			if(altitude[i]>last)
			{
				sum+=altitude[i]-last;
			}
			else
				last = altitude[i];
		}
		return sum;
	}

};
