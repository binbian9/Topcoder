#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


class TheKnights {

	public: double find(int n, int a, int b) {
		int i,j;
		vector<vector<int> > v;
		vector<vector<int> > v2;
		for(i=0;i<n;i++)
		{
			vector<int> k;
			v.push_back(k);
			v2.push_back(k);
			for(j=0;j<n;j++)
			{
				v[i].push_back(0);
				v2[i].push_back(0);
			}
		}
		int sum =0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				int counter=0;
				if((i-a)>=0 && (j-b)>=0)
									counter++;
								if((i-a)>=0 && (j+b)<n)
									counter++;
								if((i+a)<n && (j-b)>=0)
									counter++;
								if((i+a)<n && (j+b)<n)
									counter++;
								if((i-b)>=0 && (j-a)>=0)
									counter++;
								if((i-b)>=0 && (j-a)<n)
									counter++;
								if((i-b)<n && (j-a)>=0)
									counter++;
								if((i-b)<n && (j-a)<n)
									counter++;
				v[i][j]=counter;
				sum+=counter;
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if((i-a)>=0 && (j-b)>=0)
					v2[i][j] = v[i][j]+v[i-a][j-b];
				if((i-a)>=0 && (j+b)<n)
					v2[i][j] = v[i][j]+v[i-a][j-b];
				if((i+a)<n && (j-b)>=0)
					v2[i][j] = v[i][j]+v[i-a][j-b];
				if((i+a)<n && (j+b)<n)
					v2[i][j] = v[i][j]+v[i-a][j-b];
				if((i-b)>=0 && (j-a)>=0)
					v2[i][j] = v[i][j]+v[i-a][j-b];
				if((i-b)>=0 && (j-a)<n)
					v2[i][j] = v[i][j]+v[i-a][j-b];
				if((i-b)<n && (j-a)>=0)
					v2[i][j] = v[i][j]+v[i-a][j-b];
				if((i-b)<n && (j-a)<n)
					v2[i][j] = v[i][j]+v[i-a][j-b];
			}
		}
		return double();
	}

};
