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

class PlatypusPaternity {

  public: int maxFamily(vector <string> femaleCompatibility, vector <string> maleCompatibility, vector <string> siblingGroups) {
             int dads=maleCompatibility.size();
             int moms=femaleCompatibility.size();
             int subs=siblingGroups.size();
             int len=siblingGroups[0].length();
             int ans=0;
             for(int i=0;i<dads;i++)
             {
                for(int j=0;j<moms;j++)
                {
                   for(int k=0;k<subs;k++)
                   {
                      int m=0;
                      for(int l=0;l<len;l++)
                      {
                         if(siblingGroups[k][l]=='Y' &&maleCompatibility[i][l]=='Y' && femaleCompatibility[j][l]=='Y')
                            if(m==0)
                               m=3;
                            else
                               m++;
                         else if(siblingGroups[k][l]=='Y' && (maleCompatibility[i][l]!='Y' || femaleCompatibility[j][l]!='Y'))
                         {
                            m=0;
                            break;
                         }
                      }
                      ans=max(ans,m);
                   }
                }
             }
		return ans;
	}

};
