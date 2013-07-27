#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
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

class FoxPlayingGame {

  public: 
     double ans;
     int sizea;
     int sizeb;
     double sa;
     double sb;
     void cal(int nA,int nB,double val)
     {
        if(nA==sizea && nB==sizeb)
        {
           ans = max(ans,val);
           return ;
        }
        if( nB!=sizeb)
        {
           cal(nA,nB+1,val*sb);
        }
        if(nA!=sizea)
           cal(nA+1,nB,val+sa);
        return;
     }
     
     double theMax(int nA, int nB, int paramA, int paramB) {
             sa = paramA/1000.0;
             sb = paramB/1000.0;
             sizea = nA;
             sizeb = nB;
             ans = -MAX;
             if(sa==0)
                return 0;
             if(nB>0 && nA>0)
             {
                if(sa<0 && (sb>=1 || sb<=-1))
                {
                   if(sb<=-1)
                   {
                     ans = sa*nA*pow(sb,nB);
                     return sb<0&&nB%2==0?ans/sb:ans;
                   }
                   else
                   {
                      return sa*nA;
                   }
                }
                else if(sa<0 && (sb<0 && sb>-1))
                {
                   return sa*nA*sb;
                }
                else if(sa<0 && (sb>=0 && sb<1))
                {
                   return sa*nA*pow(sb,nB);
                }
                else if(sa>0 && (sb>=1 ||sb<=-1))
                {
                   ans = sa*nA*pow(sb,nB);
                   return sb<0&&nB%2!=0?ans/sb:ans;
                }
                else if(sa>0 && (sb<1 && sb>-1))
                {
                   return sa*nA;
                }

             }
             else if(nA>0 && nB==0)
             {
                return nA*sa;
             }
             else 
                return 0;
               //cal(1,0,sa);
             //cal(0,1,0);
		return ans;
	}

};
