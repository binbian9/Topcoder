#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


class Soccer {

	public: int maxPoints(vector<int> wins, vector<int> ties) {

		int size=ties.size();
		int max = -1;
		for(int i=0;i<size;i++)
		{
			if(wins[i]*3+ties[i]>max)
				max = wins[i]*3+ties[i];
		}
		return max;
	}

};
