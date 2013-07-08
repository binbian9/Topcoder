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

class MonochromaticBoard {

  public: int theMin(vector <string> board) {
             int row = board.size();
             int col = board[0].length();
             int i,j;
             int counter=0;
             for(i=0;i<row;i++)
             {
                for(j=0;j<col;j++)
                {
                   if(board[i][j]=='W')
                      break;
                }
                if(j==col)
                   counter++;
             }
             int t=0;
             for(i=0;i<col;i++)
             {
                for(j=0;j<row;j++)
                {
                   if(board[j][i]=='W')
                      break;
                }
                if(j==row)
                   t++;
             }
             if(counter==row)
                return min(counter,t);
             else
		return counter+t;
	}

};
