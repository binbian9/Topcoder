#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;



class TheArray {

	public: int find(int n, int d, int first, int last) {

		int m,i;
		vector<int> l;
		vector<int> r;
		for(i=0;i<n;i++)
		{
			l.push_back(0);
			r.push_back(0);
		}
		m =max(first,last);
		//s = min(first,last);
		if(d==0)
			return m;
		r[n-1]=last;
		for(i=0;i<n;i++)
		{
			l[i]=first+i*d;
			r[n-i-1]=last+i*d;
		}
		int x = -999999999;
		for(i=0;i<n;i++)
		{
			if(min(l[i],r[i])>x)
				x = min(l[i],r[i]);
			//cout<<x<<endl;
		}

		//cout<<x<<endl;
		return x;
	}

};
