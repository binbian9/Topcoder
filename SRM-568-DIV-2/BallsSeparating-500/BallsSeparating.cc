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

class BallsSeparating {

  public: int minOperations(vector <int> red, vector <int> green, vector <int> blue) {
             int size = red.size();
             if(size<3)
                return -1;
             int sum = 0;
             for(int i=0;i<size;i++)
                sum+= red[i]+green[i]+blue[i];
             int mm = MAX;
             for(int r=0;r<size;r++)
             {
                for(int g=0;g<size;g++)
                {
                   for(int b=0;b<size;b++)
                   {
                      if(r==g || g==b || b==r)
                         continue;
                      int s=0;
                      for(int l=0;l<size;l++)
                      {
                         s+=red[l]+green[l]+blue[l];
                         if(l==r)
                            s-=red[l];
                         else if(l==g)
                            s-=green[l];
                         else if(l==b)
                            s-=blue[l];
                         else
                            s-=max(red[l],max(green[l],blue[l]));
                      }
                      if(mm>s)
                         mm=s;
                   }

                }

             }
		return mm;
	}

};
