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

class MagicalGirlLevelOneDivTwo {

  public: double theMinDistance(int d, int x, int y) {
             if(abs(x)<=d && abs(y)<=d)
                return 0;
             double length = sqrt(x*x + y*y);
             double dx = x/length;
             double dy = y/length;
             double dd = sqrt(2*d*d);
             int newx = (int)(dx*(length-dd));
             int newy = (int)(dy*(length-dd));

             double mmm = MAX;
             for(int i=-3000;i<4000;i++)
             {
                for(int j=-3000;j<4000;j++)
                {
                   int tx = newx+i;
                   int ty = newy+j;
                   if(abs(x-tx)<=d && abs(y-ty)<=d)
                   {
                      double temp = sqrt(tx*tx+ty*ty);
                      if(temp<mmm)
                         mmm = temp;
                   }
                }
             }
		return mmm;
	}

};
