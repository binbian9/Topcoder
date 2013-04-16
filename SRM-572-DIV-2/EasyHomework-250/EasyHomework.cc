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

class EasyHomework {

  public: string determineSign(vector <int> A) {
             int size = A.size();
             int a = 0;
             if(A[0]==0)
                return "ZERO";
             if(A[0]<0)
                a = -1;
             else
                a = 1;
             for(int i=1;i<size;i++)
             {
                if(A[i]==0)
                   return "ZERO";
                else if(A[i]<0)
                   a = a*(-1);
                  
             }
             if(a<0)
                return "NEGATIVE";
             else
                return "POSITIVE";
	}

};
