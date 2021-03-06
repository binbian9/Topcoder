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

class NetworkXZeroOne {

  public: string reconstruct(string message) {
             int size = message.size();
             int t=0;
             int index=0;
             for(int i=0;i<size;i++)
             {
                if(message[i]=='o')
                {
                   t=0;
                   index=i;
                   break;
                }
                if(message[i]=='x')
                {
                   t=1;
                   index=i;
                   break;
                }
             }
             stringstream ss;
             if((index%2==0 && t==0) || (index%2==1 && t==1))
             {
                for(int i=0;i<size;i++)
                {
                   if(i%2==0)
                     ss<<"o";
                   else
                      ss<<"x";
                }
             }
             else
             {
                for(int i=0;i<size;i++)
                {
                   if(i%2==0)
                      ss<<"x";
                   else
                      ss<<"o";
                }
             }
		return ss.str();
	}

};
