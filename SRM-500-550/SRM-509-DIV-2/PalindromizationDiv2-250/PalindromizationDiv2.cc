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

class PalindromizationDiv2 {

  public: 
     bool pal(int a)
     {
        stringstream ss;
        ss<<a;
        string s = ss.str();
        int size = s.length();
        for(int i=0;i<size/2;i++)
        {
           if(s[i]!=s[size-1-i])
              return false;
        }
        return true;
     }
     int getMinimumCost(int X) {
        for(int i=0;i<=X;i++)
        {
           if(pal(X-i))
              return i;
           if(pal(X+i))
              return i;
        }
		return 0;
	}

};
