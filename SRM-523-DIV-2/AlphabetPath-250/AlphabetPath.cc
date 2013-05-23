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

class AlphabetPath {

  public: string doesItExist(vector <string> letterMaze) {
             int row = letterMaze.size();
             int col = letterMaze[0].length();
             int x=0,y=0;
             for(int i=0;i<row;i++)
               for(int j=0;j<col;j++)
                  if(letterMaze[i][j]=='A')
                     x=i,y=j;
             bool move = true;
             int c = 'A';
             while(move)
             {
                move = false;
                if(c-'Z'==0)
                   return "YES";
                if(x-1>=0 && letterMaze[x-1][y]==c+1)
                {
                   c++;x=x-1;move=true;continue;
                }
                if(x+1<row && letterMaze[x+1][y]==c+1)
                {
                   c++;x+=1;move=true;continue;
                }
                if(y-1>=0 && letterMaze[x][y-1]==c+1)
                {
                   c++;y-=1;move=true;continue;
                }
                if(y+1<col && letterMaze[x][y+1]==c+1)
                {
                   c++;y+=1;move=true;continue;
                }
             }
		return "NO";
	}

};
