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

class AntsMeet {

  public: int countAnts(vector <int> x, vector <int> y, string direction) {
             int size = x.size();
             int ans[51]= {0};
             for(int i=0;i<size;i++)
             {
                x[i]*=2;
                y[i]*=2;
             }
             for(int s=0;s<4004;s++)
             {
                for(int i=0;i<size;i++)
                {
                   if(!ans[i])
                   {
                      if(direction[i]=='N')
                         y[i]++;
                      else if(direction[i]=='S')
                         y[i]--;
                      else if(direction[i]=='W')
                         x[i]--;
                      else
                         x[i]++;
                   }
                }
                for(int i=0;i<size;i++)
                {
                   for(int j=i+1;j<size;j++)
                   {
                      if(ans[i]!=2 && ans[j]!=2 && x[i]==x[j] && y[i]==y[j])
                      {
                         ans[i]=1;
                         ans[j]=1;
                      }
                   }
                }
                for(int i=0;i<size;i++)
                   if(ans[i]==1)
                      ans[i]=2;
             }

             int counter=0;
             for(int i=0;i<size;i++)
             {
                if(ans[i]==0)
                   counter++;
             }
		return counter;
	}

};
