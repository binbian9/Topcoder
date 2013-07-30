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

class TeamsSelection {

  public: string simulate(vector <int> preference1, vector <int> preference2) {
             int ccc[55]={0};
             int size = preference1.size();
             stringstream ss;
             bool turn = true;
             int i1=0;
             int i2=0;
             for(int i=0;i<size;i++)
             {
                bool change = false;
                if(turn)
                {
                  while(!change)
                  {
                     if(ccc[preference1[i1]]==0)
                     {
                        ccc[preference1[i1]]=1;
                        change = true;
                     }
                     i1++;
                  }
                }
                else
                {
                   while(!change)
                   {
                      if(ccc[preference2[i2]]==0)
                      {
                         ccc[preference2[i2]]=2;
                         change = true;
                      }
                      i2++;
                   }
                }
                turn = turn^1;

             }
             for(int i=1;i<=size;i++)
             {
                ss<<ccc[i];
             }
		return ss.str();
	}

};
