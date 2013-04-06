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

template <typename T1, typename T2>
struct less_second {
    typedef pair<T1, T2> type;
    bool operator ()(type const& a, type const& b) const {
        return a.second < b.second;
    }
};
class CityMap {

	public: string getLegend(vector<string> cityMap, vector<int> POIs) {
		map<char,int> m;
		map<char,int>::iterator iter;
		int W=cityMap.size();
		int H = cityMap[0].length();
		for(int i=0;i<W;i++)
		{
			for(int j=0;j<H;j++)
			{
				if(cityMap[i][j]=='.')
					continue;
				iter = m.find(cityMap[i][j]);
				if(iter==m.end())
					m.insert(pair<char,int>(cityMap[i][j],1));
				else
					iter->second++;
			}
		}
		vector<pair<char, int> > mapcopy(m.begin(), m.end());
		sort(mapcopy.begin(), mapcopy.end(), less_second<char, int>());
		stringstream ss;
		W = mapcopy.size();
		H = POIs.size();
		for(int i=0;i<H;i++)
		{
			for(int j=0;j<W;j++)
			{
				if(mapcopy[j].second==POIs[i])
					ss<<mapcopy[j].first;
			}

		}
		return ss.str();
	}

};
