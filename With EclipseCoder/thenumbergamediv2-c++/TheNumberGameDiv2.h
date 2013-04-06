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

class TheNumberGameDiv2 {


	public:
	int BB;
	int mink;
	map<int,int> m;
	int minimumMoves(int A, int B) {
		BB = B;
		mink = MAX;
		if(A==B)
			return 0;
		mm(A/10,1);
		stringstream ss;
		ss<<A;
		string s=ss.str();
		reverse(s.begin(),s.end());
		ss.str("");
		ss<<s;
		int c=0;
		ss>>c;
		//cout<<c<<endl;
		if(c!=0)
			mm(c,1);

		if(mink==MAX)
			return -1;
		else
			return mink;
	}
	void mm(int a,int count)
	{

		//cout<<a<<":"<<count<<":"<<BB<<endl;
		if(m.find(a)!=m.end() && m[a]>=count)
			return;
		if(m.find(a)==m.end())
			m[a]=count;
		else
			m[a]=min(count,m[a]);
		if(a==BB)
		{
			mink = min(count,mink);
			//cout<<mink<<endl;
		}
		if(a/10!=0 && (m.find(a/10)==m.end()||m[a/10]>count+1))
			mm(a/10,count+1);
		stringstream ss;
		ss<<a;
		string s=ss.str();
		reverse(s.begin(),s.end());
		ss.str("");
		ss<<s;
		int c ;
		ss>>c;
		if(c!=0 && (m.find(c)==m.end()||m[c]>count+1))
			mm(c,count+1);

	}

};
