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

class ChickenOracle {

  public: string theTruth(int n, int eggCount, int lieCount, int liarCount) {
             int m = min(lieCount,liarCount);
             bool egg = false;
             bool chick = false;
             for(int i=0;i<=m;i++)
             {
                if(lieCount + liarCount - i>n)
                   continue;
                int correct = n - (lieCount + liarCount - 2*i);
                //cout<<"correct="<<correct<<endl;
                if(correct == eggCount)
                {
                   cout<<"egg i="<<i<<", correct="<<correct<<endl;
                   egg = true;
                }
                if(correct == n-eggCount)
                {
                   chick = true;
                   cout<<"chick i="<<i<<", correct="<<correct<<endl;
                }
             }
             if(egg && !chick)
                return "The egg";
             else if(!egg && chick)
                return "The chicken";
             else if(egg && chick)
                return "Ambiguous";
             else
		return "The oracle is a lie";
	}

};
