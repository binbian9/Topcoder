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

class RandomColoringDiv2 {

  public: int getCount(int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2) {
             int counter=0;
             for(int i=0;i<1;i++)
             {
                for(int r=0;r<maxR;r++)
                {
                   for(int g=0;g<maxG;g++)
                   {
                      for(int b=0;b<maxB;b++)
                      {
                         if(abs(r-startR)<=d2 && abs(g-startG)<=d2 && abs(b-startB)<=d2)
                         {
                            if( abs(r-startR)>=d1||abs(g-startG)>=d1||abs(b-startB)>=d1)
                               counter++;
                         }
                         //else
                            //cout<<"r="<<r<<",g="<<g<<",b="<<b<<endl;
                      }
                   }
                }
             }
		return counter++;
	}

};
