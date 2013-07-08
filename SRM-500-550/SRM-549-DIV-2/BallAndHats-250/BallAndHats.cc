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

class BallAndHats {

  public: int getHat(string hats, int numSwaps) {
             int index =0;
             for(int i=0;i<3;i++)
             {
                if(hats[i]=='o')
                {
                   index = i;
                   break;
                }
             }
             if(numSwaps==0)
                return index;
             if(numSwaps%2==0)
             {
                if(index==1)
                   return 1;
                else
                   return 0;
             }
             else
             {
                if(index==1)
                   return 0;
                else
                   return 1;
             }
	}

};
