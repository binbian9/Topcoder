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

class Filtering {

  public:
     struct fil{
        int value;
        char data;
        bool operator<(const fil& a) const
        {
           return value < a.value;
        }
     };
     bool compare(const fil &a, const fil &b)
     {
            return a.value < b.value;
     }
     vector <int> designFilter(vector <int> sizes, string outcome) {
        vector<struct fil> v;
        vector<int> ans;
        int size = sizes.size();
        for(int i=0;i<size;i++)
        {
            struct fil fff;
            fff.value = sizes[i];
            fff.data = outcome[i];
            v.push_back(fff);
        }
        sort(v.begin(),v.end());
        bool start = false;
        int count = 0;
        int sss=-1,eee=-1;
        for(int i=0;i<size;i++)
        {
           if(v[i].data=='A' && !start)
           {
              start = true;
              count ++;
              sss = i;
           }
           if(v[i].data=='A' && start)
              eee = i;
           if(v[i].data=='R' && start)
           {
              start = false;
              eee = i-1;
           }
        }
        if(count>1)
           return ans;
        else if(count==1 && eee == -1)
           eee = size -1;

        ans.push_back(v[sss].value);
        ans.push_back(v[eee].value);
	   return ans;
	}

};
