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

class AverageAverage {

  public: 
     double ans;
     int size;
     int ccc;
     void cal(int depth,vector<int> list,int c,double sum)
     {
        if(depth!=size)
        {
           cal(depth+1,list,c+1,sum+list[depth]);
           cal(depth+1,list,c,sum);
        }
        else
        {
           if(c!=0 || sum!=0)
           {
              ans+=sum/c;
              ccc++;
           }
        }
     }
     double average(vector <int> numList) {
        ans = 0.0;
        ccc = 0;
           size = numList.size();
           cal(0,numList,0,0.0);
		return ans/ccc;
	}

};
