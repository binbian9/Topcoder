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

class TheBrickTowerEasyDivTwo {

  public: 
     int h[50000];
     int find(int redCount, int redHeight, int blueCount, int blueHeight) {
        for(int i=0;i<50000;i++)
           h[i]=0;
        cc(false,redCount,blueCount,redHeight,blueHeight,0);
        cc(true,redCount,blueCount,redHeight,blueHeight,0);
        int sum=0;
        for(int i=0;i<50000;i++)
           if(h[i]==1)
              sum++;
		return sum;
	}
     void cc(bool isred,int rc,int bc,int rh,int bh,int hi)
     {
        if(isred)
        {
           if(bc>0)
           {
              hi=hi+bh;
              h[hi]=1;
              cc(false,rc,bc-1,rh,bh,hi);
           }
        }
        else
        {
           if(rc>0)
           {
              hi=hi+rh;
              h[hi]=1;
              cc(true,rc-1,bc,rh,bh,hi);
           }
        }
     }

};
