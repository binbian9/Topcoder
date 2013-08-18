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

class CarrotBoxesEasy {

  public: 
     struct so{
        int i;
        int c;
        bool operator<(const so & a) const{
           if(c>a.c)
              return true;
           else if(c<a.c)
              return false;
           else {
              return i<a.i;
           }
        }
     };
     int theIndex(vector <int> carrots, int K) {
             int size = carrots.size();
             if(size<2)
                return 0;
             vector<struct so> v;
             for(int i=0;i<size;i++)
             {
                so ss;
                ss.i = i;
                ss.c = carrots[i];
                v.push_back(ss);
             }
             sort(v.begin(),v.end());
             int ans = 0;
             while(K>0 && v[0].c>0)
             {
                int d = v[0].c - v[1].c;
                if(d==0)
                {
                   
                   v[0].c --;
                   K--;
                }
                else {
                   v[0].c -= d;
                   K -= d;
                }
                cout<<"d="<<d<<endl;
                ans = v[0].i;
                sort(v.begin(),v.end());
             }

		return ans;
	}

};
