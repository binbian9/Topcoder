#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>

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

class Starport {

  public: 
     long lcm(long m, long n)
     {
        return m / gcd(m, n) * n;
     }
     double getExpectedTime(int N, int M) {
        /*
        vector<int> v;
        long long int zz = lcm(N,M);
        int gc = gcd(M,N);
        int count = 0;
        long long int mi = 1;
        long long int ni = 1;
        long long int i = 1;
        double sum = 0.0;
        cout<<"LCM="<<zz<<endl;
        cout<<"GCD="<<gc<<endl;
        double last = -1.0;
        while(true)
        {
           if(i%M==0)
              v.push_back(i);
           if(i%N==0)
           {
              int sz = v.size();
              for(int j=0;j<sz;j++)
              {
                 //cout<<"v[j]="<<v[j]<<endl;
                 sum+=(i-v[j]+0.0);
                 count++;
              }
              v.clear();
              //cout<<"sum="<<endl;
              //cout<<"count="<<count<<endl;
           }
           if(i==zz)
              break;
           while(N*ni<=i)
              ni++;
           while(M*mi<=i)
              mi++;
           if(N*ni<M*mi)
           {
              i = N*ni;
              ni++;
           }
           else
           {
              i = M*mi;
              mi++;
           }
           //if(fabs(sum-last)<0.0000000001)
           //   break;
           //else
           {
              last = sum;
           }
           cout<<"sum/count="<<sum/count<<endl;
           //cout<<"i="<<i<<endl;
        }
        cout<<"sum="<<sum<<endl;
        cout<<"coutn="<<count<<endl;
		return sum/count;
	}
     */

     long long d = gcd(N,M);
     long long n = N/d;
     return 1.0 * d * (n-1) * n / 2 / n;
}

};
