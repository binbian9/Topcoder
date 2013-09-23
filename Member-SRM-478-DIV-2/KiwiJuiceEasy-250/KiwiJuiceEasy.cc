#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
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

class KiwiJuiceEasy {

  public: vector <int> thePouring(vector <int> capacities, vector <int> bottles, vector <int> fromId, vector <int> toId) {
             int m = fromId.size();
             for(int i=0;i<m;i++)
             {
                int w1 = bottles[fromId[i]];
                int w2 = bottles[toId[i]];
                int c2 = capacities[toId[i]];
                if(w1+w2<=c2)
                {
                   bottles[toId[i]]+=w1;
                   bottles[fromId[i]]=0;
                }
                if(w1+w2>c2)
                {
                   bottles[fromId[i]]=w1+w2-c2;
                   bottles[toId[i]]=c2;
                }
             }
		return bottles;
	}

};
