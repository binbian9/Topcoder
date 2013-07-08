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

class RotatedClock {

  public: string getEarliest(int hourHand, int minuteHand) {
             vector<string> v;
             for(int i=0;i<12;i++)
             {
                int mm = (minuteHand+30*i)%360;
                int hh = (hourHand+30*i)%360;
                int time = hh*2;
                int h = time/60;
                int m = time%60;
                //cout<<h<<":"<<m<<endl;
                if(m*6==mm)
                {
                   stringstream ss;
                   if(h<10)
                      ss<<"0";
                   ss<<h<<":";
                   if(m<10)
                      ss<<"0";
                   ss<<m;
                   v.push_back(ss.str());
                }
             }
             sort(v.begin(),v.end());
             if(v.size()==0)
                return "";
             else
                return v[0];
	}

};
