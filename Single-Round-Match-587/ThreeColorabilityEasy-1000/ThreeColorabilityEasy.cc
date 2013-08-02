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

class ThreeColorabilityEasy {

  public: string isColorable(vector <string> cells) {
             int H = cells.size();
             int W = cells[0].length();
             vector< vector< vector<int> > > v;
             vector< vector<int> > color;
             for(int i=0;i<=H;i++)
             {
                vector< vector<int> > t;
                vector< int > tp;
                color.push_back(tp);
                v.push_back(t);
                for(int j=0;j<=W;j++)
                {
                   color[i].push_back(0);
                   vector< int> q;
                   v[i].push_back(q);
                   
                }
             }

             for(int i=0;i<=H;i++)
             {
                for(int j=0;j<=W;j++)
                {
                   int a,b,c,d;
                   a=0;
                   b=0;
                   c=0;
                   d=0;
                   int cc[4]={0};
                   if(i-1>=0 && j-1>=0 && cells[i-1][j-1]=='N')
                      a = color[i-1][j-1];
                   if(j-1>=0)
                      b = color[i][j-1];
                   if(i-1>=0 && j+1<=W && cells[i-1][j+1]=='Z')
                      c = color[i-1][j+1];
                   if(i-1>=0)
                      d = color[i-1][j];
                   cc[a]++;
                   cc[b]++;
                   cc[d]++;
                   cc[c]++;
                   if(cc[1]&&cc[2]&&cc[3])
                      return "No";
                   for(int k=1;k<4;k++)
                   {
                      if(cc[k]==0)
                        color[i][j]= k;
                   }
                   cout<<color[i][j];
                }
                cout<<endl;
             }



		return "Yes";
	}

};
