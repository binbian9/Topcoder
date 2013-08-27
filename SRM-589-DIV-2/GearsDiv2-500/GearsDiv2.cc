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

class GearsDiv2 {

  public:
     vector<string> v;
     bool check(string s)
     {
        int size = s.length();
        for(int i=0;i<size;i++)
        {
           if(s[i]!='Z' && s[i]==s[(i+1)%size])
              return false;
        }
        return true;
     }
     int cal(int level)
     {
        int size = v.size();
        int l = v[0].length();
        vector<string> temp;
        for(int i=0;i<size;i++)
        {
           string s = v[i];
           for(int j=0;j<l;j++)
           {
              if(s[j]!='Z')
              {
                 string z = s;
                 z[j]='Z';
                 temp.push_back(z);
              }
           }
        }
        v.clear();
        size = temp.size();
        for(int i=0;i<size;i++)
        {
           v.push_back(temp[i]);
           if(check(temp[i]))
              return level;
        }
        return 0;

     }
     int getmin(string Directions) {
        int sum = 0;
        int size = Directions.length();
        char t = Directions[0];
        int sss = 0;
        for(int i=1;i<=size;i++)
        {
           if(Directions[i%size]==t)
           {
              sum++;
              t = 'Z';
           }
           else
              t = Directions[i];
        }
        sss = sum;
        sum = 0;
        t = Directions[size-1];
        for(int i=size-2;i>=-1;i--)
        {
           if(Directions[(i+size)%size]==t)
           {
              sum++;
              t='Z';
           }
           else
              t = Directions[i];
        }
		return min(sss,sum);
     }

};
