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

class SurroundingGameEasy {

  public: int score(vector <string> cost, vector <string> benefit, vector <string> stone) {
             int row = cost.size();
             int col = cost[0].length();
             int c = 0;
             int sum = 0;
             for(int i=0;i<row;i++)
             {
                for(int j=0;j<col;j++)
                {
                   int s=0;
                   int m=0;
                   if(i-1>=0)
                   {
                      s++;
                      if(stone[i-1][j]=='o')
                         m++;
                   }     
                   if(i+1<row)
                   {
                      s++;
                      if(stone[i+1][j]=='o')
                         m++;
                   }
                   if(j+1<col)
                   {
                      s++;
                      if(stone[i][j+1]=='o')
                         m++;
                   }
                   if(j-1>=0)
                   {
                      s++;
                      if(stone[i][j-1]=='o')
                         m++;
                   }
                   if(s==m || stone[i][j]=='o')
                      sum+=benefit[i][j]-'0';
                   if(stone[i][j]=='o')
                      c+=cost[i][j]-'0';
                      

                }
             }


		return sum-c;
	}

};
