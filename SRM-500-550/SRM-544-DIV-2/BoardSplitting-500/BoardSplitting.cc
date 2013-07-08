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

class BoardSplitting {

  public: int minimumCuts(int desiredLength, int desiredCount, int actualLength) {
             int cut=0;
             int board=0;
             while(desiredCount>0)
             {
                if(board==desiredLength)
                {
                   board=0;
                }
                else if(board<desiredLength)
                {
                   while(board<desiredLength)
                   {
                        board+=actualLength;
                   }
                   board-=desiredLength;
                   if(board!=0)
                     cut++;
                   
                   cout<<board<<endl;
                }
                else if(board>desiredLength)
                {
                   board-=desiredLength;
                   cut++;
                }
                desiredCount--;
             }
		return cut;
	}

};
