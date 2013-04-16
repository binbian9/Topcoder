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

class NextOrPrev {

  public: int getMinimum(int nextCost, int prevCost, string start, string goal) {
             int size = start.length();
             for(int i=0;i<size;i++)
             {
                for(int j=0;j<size;j++)
                {
                   if(i==j){continue;}
                   if(start[i]-goal[i]<0)
                   {
                      if(((goal[j]<goal[i] && goal[j]>=start[i]) || (start[j]<goal[i] && start[j]>=start[i])))
                      {
                         if(start[j]-goal[j]>=0){ return -1;}
                         else
                         {
                            if((goal[j]<goal[i] && goal[j]>=start[i]) && (start[j]<goal[i] && start[j]>=start[i]))
                            {return -1;}
                         }
                      }
                   }
                   else
                   {
                      if(((goal[j]<=start[i] && goal[j]>goal[i])||(start[j]<=start[i] && start[j]>goal[i])))
                      {
                        if(start[j]-goal[j]<=0)
                           return -1;
                        else
                        {
                           if(((goal[j]<=start[i] && goal[j]>goal[i])&&(start[j]<=start[i] && start[j]>goal[i])))
                           {
                              return -1;
                           }
                        }

                      }
                   }

                }
             }
             int sum = 0;
             for(int i=0;i<size;i++)
             {
                if(start[i]-goal[i]>0)
                {
                   sum+=(start[i]-goal[i])*prevCost;
                }
                else
                   sum+=(goal[i]-start[i])*nextCost;
             }
		return sum;
	}

};
