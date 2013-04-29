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

class ColorfulBricks {

  public: int countLayouts(string bricks) {
             int size = bricks.length();
             map<char,int> m;
             map<char,int>::iterator iter;
             int c=0;
             for(int i=0;i<size;i++)
             {
                iter=m.find(bricks[i]);
                if(iter==m.end())
                {
                   m[bricks[i]]=1;
                   c++;
                }
             }
             if(c==1)
                return 1;
             else if(c==2)
                return 2;
             else 
		return 0;
	}

};
