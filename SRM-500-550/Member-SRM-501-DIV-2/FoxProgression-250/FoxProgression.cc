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

class FoxProgression {

  public: int theCount(vector <int> seq) {
             int size = seq.size();
             if(size == 1)
                return -1;
             bool ca = true;
             bool cb = true;
             int diff=(seq[1]-seq[0]);
             double r = (seq[1]+0.0)/seq[0];
             for(int i=2;i<size;i++)
             {
                if(seq[i]-seq[i-1]-diff!=0)
                   ca = false;
                if(fabs((seq[i]-0.0)/seq[i-1]-r)>0.000001)
                   cb = false;
             }
             if(ceil(r)!=floor(r))
                cb = false;
             int a = (seq[size-1] + diff);
             int b = (int)(seq[size-1]*r);
             cout<<ca<<" , "<<cb<<",a="<<a<<",b="<<b<<endl;
             if(ca && cb && a!=b)
                return 2;
             else if(ca||cb)
                return 1;

		return 0;
	}

};
