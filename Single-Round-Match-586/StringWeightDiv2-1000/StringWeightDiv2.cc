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

class StringWeightDiv2 {

  public: int countMinimums(int L) {
             long long v[1001]={0};
             v[0]=1;
             for(int i=1;i<=26;i++)
             {
                v[i]=(v[i-1]*(26-i+1))%1000000009;
                if(v[i]<0)
                   cout<<"v[i] OVERFLOW!!! = "<<i<<endl;
             }
             if(L<27)
                return v[L];
             /*
             for(int i=27;i<=L;i++)
             {
                long long temp = 0;
                for(int j=1;j<=i-26;j++)
                   temp = (temp + v[j])%1000000009;
                v[i]=(v[i-1]*(temp))%1000000009;
                if(v[i]<0)
                   cout<<"v[i] OVERFLOW!!! = "<<i<<endl;
             }
             cout<<v[L-1]<<endl;
             cout<<v[L]<<endl;
             */
             int num = L-26;
             int mmm = 26;
             long long ans = v[26];
             while(num)
             {
                ans = (ans * (long long)(mmm--))%1000000009;
                num--;
             }
	     return ans;
	}

};
