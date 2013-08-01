#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
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

class MafiaGame {

  public: double probabilityToLose(int N, vector <int> decisions) {
             int size = decisions.size();
             int vote[550];
             memset(vote,0,550);
             map<int,int> m;
             int c=0;
             int mas = 0;
             for(int i=0;i<size;i++)
                m[decisions[i]]++;
             if(m.size()==size)
                return 0;
             for(int i=0;i<size;i++)
                vote[decisions[i]]++;
             for(int i=0;i<N;i++)
                mas = max(mas,vote[i]);
             for(int i=0;i<size;i++)
                if(vote[i]==mas)
                   c++;
             double ans = 1.0/c;
             while(c>1)
             {
                int rest = N-mas*c;
                if(rest%c==0)
                   return 0;
                c=rest%c;
             }
		return ans;
	}

};
