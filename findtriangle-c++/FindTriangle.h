#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

#define eps (le-7)
#define INF (le60)
#define MAX (1<<30)
#define MIN (-MAX)
#define LL long long

#define pb push_back

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()
#define gcd(a,b) __gcd(a,b)
#define EQ(a,b) (abs(a-b) <eps)
#define sqr(a) ((a)*(a))
#define popcount(n) __builtin_popcount(n)

inline LL strtoint(const string &s) {stringstream ss;ss<<s;LL ret;ss>>ret;return ret;}
inline string inttostr(const LL &a) {stringstream ss;ss<<a;string ret;ss>>ret;return ret;}

class FindTriangle {

	enum color
	{
		R=0,
		G=1,
		B=2
	};
	vector<int> sp(string s)
	{
		vector<int> ii;
		vector<string> v;
		string::size_type pos1,pos2;
		pos1 = 0;
		pos2 = s.find(' ');
		while(string::npos != pos2)
		{
			v.push_back(s.substr(pos1,pos2-pos1));
			pos1=pos2+1;
			pos2 = s.find(' ',pos1);
		}
		//cout<<"TEST!"<<endl;
		v.push_back(s.substr(pos1));
		stringstream ss;
		ss<<v[0];
		int i;
		ss>>i;
		//cout<<"TEST!"<<endl;
		ii.push_back(i);
		ss.clear();
		ss<<v[1];
		ss>>i;
		//cout<<"TEST!"<<endl;
		ii.push_back(i);
		ss.clear();
		ss<<v[2];
		ss>>i;
		//cout<<"TEST!"<<endl;
		ii.push_back(i);
		return ii;

	}
	double cal_size(string s1,string s2,string s3)
	{
		vector<int> v1 = sp(s1);
		vector<int> v2 = sp(s2);
		vector<int> v3 = sp(s3);
		double x1,x2,x3,y1,y2,y3,z1,z2,z3;
		x1 = v1[0];
		y1 = v1[1];
		z1 = v1[2];
		x2 = v2[0];
		y2 = v2[1];
		z2 = v2[2];
		x3 = v3[0];
		y3 = v3[1];
		z3 = v3[2];

		double a = sqrt(pow((x1-x2),2)+pow(y1-y2,2)+pow(z1-z2,2));
		double b = sqrt(pow(x3-x2,2)+pow(y3-y2,2)+pow(z3-z2,2));
		double c = sqrt(pow(x1-x3,2)+pow(y1-y3,2)+pow(z1-z3,2));
		double s = (a+b+c)/2.0;

		//print "area = ",area
		return sqrt(s*(s-a)*(s-b)*(s-c));
	}
	public: double largestArea(vector<string> points) {
		vector<string> RGB[3];
		vector<double> ans;
		int size = points.size();
		for(int i=0;i<size;i++)
		{
			int tttemp=0;
			if(points[i][0]=='R')
				tttemp = 0;
			if(points[i][0]=='G')
				tttemp = 1;
			if(points[i][0]=='B')
				tttemp = 2;
			RGB[tttemp].push_back(points[i].substr(2));
		}

		int size1 = RGB[0].size();
		if(size1>=3)
		{
			//cout<<"TEST!"<<endl;
			for(int i=0;i<size1;i++)
			{
				for(int j=i+1;j<size1;j++)
				{
					for(int k=j+1;k<size1;k++)
					{
						//cout<<"TEST!%^&$%#&"<<endl;
						//cout<<cal_size(RGB[0][i],RGB[0][j],RGB[0][k])<<endl;
						ans.push_back(cal_size(RGB[0][i],RGB[0][j],RGB[0][k]));
					}
				}
			}
		}

		int size2 = RGB[1].size();
		if(size2>=3)
		{
			//cout<<"TEST2!"<<endl;
			for(int i=0;i<size2;i++)
			{
				for(int j=i+1;j<size2;j++)
				{
					for(int k=j+1;k<size2;k++)
					{
						ans.push_back(cal_size(RGB[1][i],RGB[1][j],RGB[1][k]));
					}
				}
			}
		}

		int size3 = RGB[2].size();
		if(size3>=3)
		{
			//cout<<"TEST3!"<<endl;
			for(int i=0;i<size3;i++)
			{
				for(int j=i+1;j<size3;j++)
				{
					for(int k=j+1;k<size3;k++)
					{
						ans.push_back(cal_size(RGB[2][i],RGB[2][j],RGB[2][k]));
					}
				}
			}
		}

		//cout<<"TEST4!"<<endl;
		for(int i=0;i<size1;i++)
		{
			for(int j=0;j<size2;j++)
			{
				for(int k=0;k<size3;k++)
				{
					ans.push_back(cal_size(RGB[0][i],RGB[1][j],RGB[2][k]));
				}
			}
		}
		sort(ans.rbegin(),ans.rend());


		return ans[0];
	}

};
