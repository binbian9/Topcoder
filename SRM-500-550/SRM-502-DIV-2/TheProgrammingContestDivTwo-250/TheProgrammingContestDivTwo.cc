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

class TheProgrammingContestDivTwo {

  public: vector <int> find(int T, vector <int> requiredTime) {
             int size = requiredTime.size();
             sort(requiredTime.begin(),requiredTime.end());
             vector<int> v;
             v.push_back(0);
             v.push_back(0);
             int t = 0; 
             for(int i=0;i<size;i++)
             {
                t+=requiredTime[i];
                if(t<=T)
                {
                   v[1]+=t;
                   v[0]++;
                }
                else
                   break;
             }
		return v;
	}

};
