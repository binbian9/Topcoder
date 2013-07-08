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

class FortunateNumbers {

  public: int getFortunate(vector <int> a, vector <int> b, vector <int> c) {
             int sa = a.size();
             int sb = b.size();
             int sc = c.size();
             map<int,bool> m;
             map<int,bool>::iterator iter;
             int ans = 0;
             for(int i=0;i<sa;i++)
             {
                for(int j=0;j<sb;j++)
                {
                   for(int k=0;k<sc;k++)
                   {
                      stringstream ss;
                      int temp = a[i]+b[j]+c[k];
                      ss<<temp;
                      string s = ss.str();
                      int st = s.length();
                      bool check = true;
                      //cout<<s<<endl;
                      for(int l=0;l<st;l++)
                      {
                         if(s[l]!='5' && s[l]!='8')
                         {
                            check = false;
                            break;
                         }
                      }
                      if(check)
                      {
                         if(m.find(temp)==m.end())
                         {
                            m[temp]=true;
                            ans++;
                         }
                         
                      }
                   }
                }
             }
		return ans;
	}

};




