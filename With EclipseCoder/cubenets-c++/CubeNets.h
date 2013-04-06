#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
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

//typedef pair<int,int> pint;

class CubeNets {


	enum direction{
		U=0,
		D=1,
		R=2,
		L=3
	};

	public: string isCubeNet(vector<string> figure) {
		int array[6][4] = {{5,1,4,3},{5,2,4,0},{5,3,4,1},{5,0,4,2},{0,1,2,3},{2,1,0,3}};
		int r[6]={0};
		int l[6]={0};
		bool a[6]={0};
		bool fff[6]={0};
		map<pair<int,int>,int> m;
		map<pair<int,int > , int >::iterator iter;

		int length = figure.size();
		int width = figure[0].length();
		stack<pair<int,int>  > ss;
		for(int i=0;i<length;i++)
		{
			pair<int,int> p;
			for(int j=0;j<width;j++)
			{
				p.first = i;
				p.second = j;
				if(figure[i][j]=='#' && m.find(p)==m.end())
				{
					cout<<i<<" - "<<j<<endl;
					l[0]=0;
					r[0]= 0;
					m[p]=0;
					a[0]=true;
					ss.push(p);
					i = length+1;
					break;
				}
			}
		}
		while(!ss.empty())
		{

			pair<int,int> current=ss.top();
			int f = current.first;
			int s = current.second;
			//cout<<f<<" : "<<s<<endl;
			ss.pop();
			iter = m.find(current);
			//cout<<"TEST 0"<<endl;
			//cout<<"msize = "<<m.size()<<endl;
			cout<<"iter = "<<iter->first.first<<":"<<iter->first.second <<endl;
			if(fff[iter->second])
				continue;

			fff[iter->second] = true;

			//cout<<"TEST 1"<<endl;
			if(f-1>=0 && figure[f-1][s]=='#' && m.find(pair<int,int>(f-1, s))==m.end())
			{
				cout<<"TEST 2"<<endl;
				int i;
				int temp = l[iter->second]-r[iter->second]+0;
				if(temp<0)
					temp+=4;
				int k = array[iter->second][temp%4]; //new position
				l[k] = iter->second;
				m[pair<int,int>(current.first-1,current.second) ] = k;
				ss.push(pair<int,int>(current.first-1,current.second));
				for(i=0;i<4;i++)
				{
					if(array[k][i]==iter->second)
						break;
				}
				l[k] = i;

				r[k]=2;
				a[k]=true;
				cout<<"i= "<<i<<endl;

			}
			if(f +1<length && figure[f+1][s]=='#' && m.find(pair<int,int>(f+1, s))==m.end())
			{
				cout<<"TEST 3"<<endl;
				int i;
				int temp = l[iter->second]-r[iter->second]+2;
				if(temp<0)
					temp+=4;
				int k = array[iter->second][temp%4]; //new position
				cout<<k<<endl;
				m[pair<int,int>(current.first+1,current.second) ] = k;
				ss.push(pair<int,int>(current.first+1,current.second) );
				for(i=0;i<4;i++)
				{
					if(array[k][i]==iter->second)
						break;
				}
				l[k] = i;

				r[k]=0;
				a[k]=true;
			}
			if(s -1>=0 && figure[f][s-1]=='#' && m.find(pair<int,int>(f, s-1))==m.end())
			{
				cout<<"TEST 4"<<endl;
				int i;
				int temp = l[iter->second]-r[iter->second]+3;
				if(temp<0)
					temp+=4;
				int k = array[iter->second][temp%4]; //new position
				cout<<k<<endl;
				m[pair<int,int>(current.first,current.second-1) ] = k;
				ss.push(pair<int,int>(current.first,current.second-1));
				for(i=0;i<4;i++)
				{
					if(array[k][i]==iter->second)
						break;
				}
				l[k] = i;

				r[k]=1;
				a[k]=true;
				cout<<"i= "<<i<<endl;
			}
			if(s +1<width && figure[f][s+1]=='#' && m.find(pair<int,int>(f, s+1))==m.end())
			{
				cout<<"TEST 5"<<endl;
				int i;
				int temp = l[iter->second]-r[iter->second]+1;
				if(temp<0)
					temp+=4;
				int k = array[iter->second][temp%4]; //new position
				cout<<k<<endl;
				m[pair<int,int>(current.first,current.second+1) ] = k;
				ss.push(pair<int,int>(current.first,current.second+1) );
				for(i=0;i<4;i++)
				{
					if(array[k][i]==iter->second)
						break;
				}
				l[k] = i;

				r[k]=3;
				a[k]=true;
				cout<<"i= "<<i<<endl;
			}

		}
		for(int i=0;i<6;i++)
			cout<<"r[i]="<<r[i]<<endl;
		for(int i=0;i<6;i++)
			if(!a[i])
				return "NO";

		return "YES";
	}

};
