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

class TheNumberGameDiv2 {

  public: int minimumMoves(int A, int B) {
             stringstream ss;
             ss<<B;
             string b = ss.str();
             stringstream s2;
             s2<<A;
             string a = s2.str();
             cout<<"a="<<a<<endl;
             cout<<"b="<<b<<endl;
             int size = a.length();
             //string rb = reverse(b.begin(),b.end());
             int sum = 9999999;
             int sum2 = 9999999;
             unsigned found = a.find(b);
             unsigned found2 = 0;
             cout<<"b4 found"<<endl;
             if(found<=size)
             {
                cout<<"af found = "<<found<<endl;
                sum = size - (found+b.size());
                if(found)
                   sum+=2;
                sum += found;
             }
             reverse(a.begin(),a.end());
             found2 = a.find(b);
             cout<<"b4 found2 = "<<found2<<endl;
             if(found2<=size)
             {
                sum2 = size - (found2+b.size());
                sum2+=1;
                sum2 += found2;
             }
             if(found >size && found2 >size)
                return -1;
             cout<<"sum = "<<sum<<endl;
             cout<<"sum2 = "<<sum2<<endl;

		return min(sum,sum2);
	}

};
