#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
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

class TheCoffeeTimeDivTwo {

  public: int find(int n, vector <int> tea) {
             //serve = 4 s
             //walk  = 1 s
             //refill = 47s
             int size = tea.size();
             int serve[1001]={0};
             int t = size;
             int c = n-size;
             int sum = 0;
             for(int i=0;i<size;i++)
             {
                serve[tea[i]]=1;//tea
             }
             for(int i=1;i<=n;i++)
             {
                if(serve[i]==0)
                   serve[i]=2; //coffee
             }
             int time = ceil(t/7.0);
             int last = n;
             for(int j=0;j<time;j++)
             {
                sum +=47;
                int z = 7;
                for(int i=last;i>0 && z>0;i--)
                {
                   if(serve[i]==1)
                   {
                      if(z==7)
                         sum+=2*(i);
                      z--;
                      sum+=4;
                      cout<<"tea:"<<i<<", time:"<<sum<<endl;
                      serve[i]=0;
                      last = i;
                   }
                }
             }
             cout<<"time:"<<sum<<endl;
             time = ceil(c/7.0);
             last = n;
             for(int j=0;j<time;j++)
             {
                sum+=47;
                int z = 7;
                for(int i=last;i>0 &&z>0;i--)
                {
                   if(serve[i]==2)
                   {
                      if(z==7)
                         sum+=2*(i);
                      z--;
                      sum+=4;
                      serve[i]=0;
                      last = i;
                   }
                }
             }
             cout<<"time:"<<sum<<endl;
		return sum;
	}

};
