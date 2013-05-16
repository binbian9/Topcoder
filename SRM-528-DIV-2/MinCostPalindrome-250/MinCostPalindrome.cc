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

class MinCostPalindrome {

  public: int getMinimum(string s, int oCost, int xCost) {
             int size = s.length();
             int sum=0;
             if(size%2!=0)
                if(s[size/2+1]=='?')
                   sum=min(oCost,xCost);
             for(int i=0;i<size/2;i++)
             {
                if(s[i]-s[size-1-i]!=0)
                {
                   if(s[i]!='?' && s[size-1-i]!='?')
                      return -1;
                   else if(s[i]=='o' || s[size-1-i]=='o')
                      sum+=oCost;
                   else
                      sum+=xCost;
                }
                else if(s[i]=='?' && s[i]=='?')
                   sum+=min(oCost,xCost)*2;
             }

		return sum;
	}

};
