#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

class Predicting {

	public: double avgError(vector<double> data) {
		int a,b,c,d,e;
		double array[21]={-1.0,-0.9,-0.8,-0.7,-0.6,-0.5,-0.4,-0.3,-0.2 , -0.1, 0.0,
				0.1, 0.2,0.3,0.4,0.5,0.6,0.7,0.8, 0.9, 1.0};

		int i;
		int size=data.size();
		double min=9999999.9;
		for(a=0;a<21;a++)
			for(b=0;b<21;b++)
				for(c=0;c<21;c++)
					for(d=0;d<21;d++)
						for(e=0;e<21;e++)
						{
							if(fabs(array[a]+array[b]+array[c]+array[d]+array[e])-1>1E-9)
								continue;
							double err=0.0;
							for(i=0;i<size-5;i++)
							{
								double zz = data[i]*array[a]+data[i+1]*array[b]+data[i+2]*array[c]+data[i+3]*array[d]+data[i+4]*array[e];
								err += abs(data[i+5]-zz);
							}
							if(err<min)
								min=err;
						}

		return min/(size-5);
	}

};
