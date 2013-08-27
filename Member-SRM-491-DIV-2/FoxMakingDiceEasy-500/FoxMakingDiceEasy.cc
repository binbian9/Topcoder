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

class FoxMakingDiceEasy {

  public: 
     int cal(int n)
     {
        return n*(n-1)*(n-2)/6;
     }
     int theCount(int N, int K) {
             if(N<6 || ((1+N)*N)/2<K)
                return 0;
             int kkk = K;
             int sum=0;
             for(int k=kkk;k<=N*2;k++)
             {
                int c = 0;
                for(int i=1;i<=N;i++)
                {
                   for(int j=i+1;j<=N;j++)
                   {
                      if(i+j==k)
                      {
                         //cout<<"i="<<i<<" j="<<j<<endl;
                         c++;
                      }
                   }
                }
                int temp = cal(c);
                if(c>=3 )
                {
                   //cout<<"c="<<c<<" temp"<<temp<<endl;
                   sum+=temp*2;
                }
             }
		return sum;
	}

};
