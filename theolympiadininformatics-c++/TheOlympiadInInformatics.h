#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


class TheOlympiadInInformatics {

	public: int find(vector<int> sums, int k) {
		int scores=0,i,j;
		int size = sums.size();
		for(i=0;i<1000000000;i++)
		{
			scores = 0;
			for(j=0;j<size;j++)
			{
				scores +=  sums[j]/(i+1);
			}
			if(scores<=k)
				return i;
		}
		return 0;
	}

};
