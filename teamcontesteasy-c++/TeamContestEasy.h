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

class TeamContestEasy {

	public: int worstRank(vector<int> strength) {
		map<int,int> m;
		map<int,int>::iterator iter;
		int size = strength.size();
		int Q = min(strength[1],strength[2]);
		int k = min(strength[0],Q);
		int me = strength[0]+strength[1]+strength[2]-k;
		vector<int> v;
		for(int i=3;i<size;i++)
		{
			v.push_back(strength[i]);
		}
		sort(v.begin(),v.end());
		int n = v.size()/3;
		int rank = 1;
		cout<<rank<<endl;
		int index = n;
		for(int i=0;i<n;i++)
		{
			if(v[size-3-i]+v[i+n]>me)
			{
					rank++;
					index++;
			}
			else
			{
				for(int j=i+1;j<n;j++)
				{
					if(v[size-3-i]+v[j+n]>me)
					{
						rank++;
						continue;
					}
				}

			}
		}
		return rank;
	}

};
