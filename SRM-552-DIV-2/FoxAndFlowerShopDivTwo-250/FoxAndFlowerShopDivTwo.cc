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

class FoxAndFlowerShopDivTwo {

  public: int theMaxFlowers(vector <string> flowers, int r, int c) {
             int a[4]={0};
             int row = flowers.size();
             int col = flowers[0].length();
             for(int k=0;k<4;k++)
             {
                for(int i=0;i<row;i++)
                {
                   for(int j=0;j<col;j++)
                   {
                      if(k==0)
                         if(j<c && flowers[i][j]=='F')
                            a[0]++;
                      if(k==1)
                         if(j>c && flowers[i][j]=='F')
                            a[1]++;
                      if(k==2)
                         if(i<r && flowers[i][j]=='F')
                            a[2]++;
                      if(k==3)
                         if(i>r && flowers[i][j]=='F')
                            a[3]++;
                   }
                }
             }
             int ans=max(max(a[0],a[1]),max(a[2],a[3]));
		return ans;
	}

};
