#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
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

class ConvertibleStrings {

  public: 
     struct sssss{
        char a;
        char b;
        vector<int> v;
        int size;
     };
     int leastRemovals(string A, string B) {
        int sum = 0;
        int size = A.length();
        map<pair<char,char> ,set<int> > m;
        map<pari<char,char> ,set<int> >::iterator iter;
        for(int i=0;i<size;i++)
        {
           pair<char,char> p = make_pair (A[i],B[i]);
           set<int> s;
           iter = m.find(p);
           if(iter!=m.end())
           {
               for(int j=0;j<size;j++)
               {
                   if(B[j]==B[i] && A[j]==A[i])
                   {
                      s.insert(j);
                   }
               }
               m[p] = s;
           }
           
        }
		return $DUMMYRETURN$;
	}

};
