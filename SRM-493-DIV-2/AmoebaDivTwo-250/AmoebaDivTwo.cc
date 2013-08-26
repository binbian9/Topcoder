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

class AmoebaDivTwo {

  public: int count(vector <string> table, int K) {
             int row = table.size();
             int col = table[0].length();

             int sum = 0;
             for(int i=0;i<row;i++)
             {
                for(int j=0;j+K<=col;j++)
                {
                   int c = 0;
                   for(int k=0;k<K;k++)
                   {
                      if(table[i][j+k]=='A')
                         c++;
                      else
                         break;
                   }
                   if(c==K)
                      sum++;
                }
             }
             if(K==1)
                return sum;
             for(int i=0;i+K<=row;i++)
             {
                for(int j=0;j<col;j++)
                {
                   int c = 0;
                   for(int k=0;k<K;k++)
                   {
                      if(table[i+k][j]=='A')
                         c++;
                      else
                         break;
                   }
                   if(c==K)
                      sum++;
                }
             }
		return sum;
	}

};
