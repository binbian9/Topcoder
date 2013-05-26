#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <cstring>
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

class EelAndRabbit {

  public: int getmax(vector <int> l, vector <int> t) {
             int size = t.size();
             if(size==1)
                return 1;
             int ans=0;
             bool check[55];
             for(int i=0;i<size;i++)
             {
                for(int j=i+1;j<size;j++)
                {
                   int best=0;
                   memset(check,false,sizeof(check));
                   for(int k=0;k<size;k++)
                   {
                      if(t[i]>=t[k] && t[i]<=t[k]+l[k] && !check[k])
                      {
                         best++;
                         check[k]=true;
                      }
                      if(t[j]>=t[k] && t[j]<=t[k]+l[k] && !check[k])
                      {
                         best++;
                         check[k]=true;
                      }
                   }
                   ans=max(ans,best);
                }
             }
		return ans;
	}

};
