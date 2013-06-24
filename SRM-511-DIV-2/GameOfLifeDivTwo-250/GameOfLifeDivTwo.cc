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

class GameOfLifeDivTwo {

  public: string theSimulation(string init, int T) {
             int size = init.length();
             cout<<init.substr(2)<<endl;
             cout<<init.substr(2,2)<<endl;
             for(int i=0;i<T;i++)
             {
                string ans=init;
                for(int j=0;j<size;j++)
                {
                   int temp = 0;
                   for(int k=-1;k<2;k++)
                   {
                      int zz=j+k;
                      if(j+k<0)
                         zz += size;
                      int a = init[(zz)%size]-'0';
                      temp += a;
                   }
                   if(temp>=2)
                      ans[j]='1';
                   else
                      ans[j]='0';
                }
                cout<<ans<<endl;
                init = ans;
             }
		return init;
	}

};
