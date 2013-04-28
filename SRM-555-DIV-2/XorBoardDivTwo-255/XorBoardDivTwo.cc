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

class XorBoardDivTwo {

  public: int theMax(vector <string> board) {
             int row = board.size();
             int col = board[0].length();
             int ans=0;
             for(int i=0;i<row;i++)
             {
                for(int j=0;j<col;j++)
                {
                   int sum=0;
                   for(int k=0;k<row;k++)
                   {
                      for(int l=0;l<col;l++)
                      {
                         int temp = board[k][l]-'0';
                         if((i!=k && j!=l) ||(i==k&&j==l))
                            sum+=temp;
                         else
                            sum= sum + (temp+1)%2;
                      }
                   }
                   ans=max(sum,ans);
                }
             }

		return ans;
	}

};
