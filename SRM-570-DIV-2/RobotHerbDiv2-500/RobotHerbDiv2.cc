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

class RobotHerbDiv2 {

  public: int getdist(int T, vector <int> a) {
             int size = a.size();
             int x=0;
             int y=0;
             int d=0;
             for(int j=0;j<T;j++)
             {
               for(int i=0;i<size;i++)
               {
                   if(d==0)
                      x+=a[i];
                  else if(d==1)
                      y-=a[i];
                  else if(d==2)
                      x-=a[i];
                  else if(d==3)
                      y+=a[i];
                  d+=a[i];
                  d%=4;
               }
             }
             int ans = abs(x)+abs(y);
		return ans;
	}

};
