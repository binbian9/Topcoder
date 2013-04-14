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

class CityMap {

  public: string getLegend(vector <string> cityMap, vector <int> POIs) {
             int size = cityMap.size();
             int wide = cityMap[0].length();
             map<char, int> m;
             map<char, int>::iterator iter;
             for(int i=0;i<size;i++)
             {
                for(int j=0;j<wide;j++)
                {
                   if(cityMap[i][j]!='.')
                   {
                      char s = cityMap[i][j];
                      iter = m.find(s);
                      if(iter == m.end())
                      {
                         m[s] = 1;
                      }
                      else
                         m[s] ++;
                   }

                }
             }
             cout<<"TEST"<<endl;
             cout<<m.size()<<endl;
             map<int,char> m2;
             map<int,char>::iterator iter2;
             for(iter = m.begin();iter!=m.end();iter++)
             {
                cout<<iter->first<<" , "<<iter->second<<endl;
                m2.insert(pair<int,char>(iter->second,iter->first));
             }
             stringstream ss;
             int ps = POIs.size();
             for(int i=0;i<ps;i++)
             {
                ss<<m2[POIs[i]];
                /*
                for(iter = m.begin();iter!=m.end();iter++)
                {
                   if(iter->second == POIs[i])
                   {
                      ss<<iter->first;
                      break;
                   }
                }
                */
             }

		return ss.str();
	}

};
