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

class LittleElephantAndPermutationDiv2 {

  public:
     int kk;
     int nn;
     int ans;
     void check(vector<int> v)
     {
        int sum = 0;
        for(int i=0;i<nn;i++)
           sum += max(v[i],i+1);
        if(sum>=kk)
           ans ++;
     }
     long long getNumber(int N, int K) {
           ans = 0;
           nn = N;
           kk = K;
           vector<int> v;
           for(int i=1;i<=N;i++)
              v.push_back(i);
           do {
              check(v);
           } while (next_permutation(v.begin(),v.end()));

           long long sss = 1;
           for(int i=1;i<=N;i++)
              sss *= i;
           
		return sss*ans;
	}

};
