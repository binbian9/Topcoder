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

class PenguinTiles {

  public: int minMoves(vector <string> tiles) {
             int x=0,y=0;
             int row = tiles.size();
             int col = tiles[0].length();
             for(x=0;x<row;x++)
             {
                for(y=0;y<col;y++)
                {
                   if(tiles[x][y]=='.')
                     goto out;
                }
             }
out:
             cout<<"x="<<x<<" Y= "<<y<<endl;

             if(x!=row-1)
                x=1;
             else
                x=0;
             if(y!=col-1)
                y=1;
             else
                y=0;
	     return x+y;
	}

};
