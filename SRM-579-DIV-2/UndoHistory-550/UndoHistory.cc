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
#define sz(x) x.size()
inline LL strtoint(const string &s) {stringstream ss;ss<<s;LL ret;ss>>ret;return ret;}
inline string inttostr(const LL &a) {stringstream ss;ss<<a;string ret;ss>>ret;return ret;}

class UndoHistory {

  public: 
     int minPresses(vector <string> lines) {
             int size = lines.size();

             int res = lines[0].length()+1;
             
             cout<<"START res="<<res<<endl;
             for(int i=1;i<size;i++)
             {
                int mx=0,my=0;
                for(int j=0;j<i;j++)
                {
                   int a=0,b=0;
                   while(a<sz(lines[i]) && b<sz(lines[j]) && lines[i][a]==lines[j][b])
                      a++,b++;
                   mx = max(a,mx);
                }

                string x = lines[i];
                string y = lines[i-1];
                int a=0,b=0;
                while(a<sz(x) && b<sz(y) && x[a]==y[b])
                   a++,b++;
                if(b==sz(y))
                   my=b;
                else
                   my=-10;
                cout<<"mx="<<mx<<", my="<<my<<endl;

                if(mx-2>my)
                   res+=sz(lines[i])-mx+2;
                else
                   res+=sz(lines[i])-my;

                res++;


               cout<<"res="<<res<<endl; 
             }
		return res;
	}

};
