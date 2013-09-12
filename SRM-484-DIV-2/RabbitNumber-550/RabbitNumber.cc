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

class RabbitNumber {

  public:
     int S(long a)
     {
        int sum = 0;
        while(true)
        {
           sum+=a%10;
           a/=10;
           if(a<=0)
              break;
        }
        return sum;
     }
     int check(string s)
     {
        int pos = s.find_last_of("4");
        int size = s.length();
        stringstream ss;
        if(pos>=0)
        {
           int p = pos;
           for(int i=0;i<size;i++)
           {
              if(i<p)
                 ss<<s[i];
              else 
                 ss<<"9";
           }
           ss>>pos;
        }
        return pos;
     }
     int theCount(int low, int high) {

        int ans = 0;
        for(int i=low;i<=high;i++)
        {
           stringstream ss1;
           ss1<<i;
           int c = check(ss1.str());
           if(c>=0)
           {
              i = c;
              continue;
           }
           int x = (S(i)*S(i));
           int y = S((long)i*i);
           if(x==y)
              ans ++;
           
        }
		return ans;
	}

};
