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

class ValueHistogram {

  public: vector <string> build(vector <int> values) {
             int size = values.size();
             vector<string> v;
             for(int i=0;i<10;i++)
                v.push_back("");
             int height[10]={0};
             int m = 0;
             for(int i=0;i<size;i++)
             {
                height[values[i]]++;
                v[values[i]].append("X");
                if(m<height[values[i]])
                   m = height[values[i]];
             }
             m++; 
             for(int i=0;i<10;i++)
             {
                int t = v[i].length();

                while(t<m)
                {
                  v[i].append(".");
                  t++;
                }
                v[i].append(".");
             }
             vector<string> ans;
             for(int i=m-1;i>=0;i--)
             {
                ans.push_back("");
                for(int j=0;j<10;j++)
                {
                   stringstream ss;
                   ss<<v[j][i];
                   ans[m-1-i].append(ss.str());
                }
                cout<<ans[m-1-i]<<endl;
             }

		return ans;
	}

};
