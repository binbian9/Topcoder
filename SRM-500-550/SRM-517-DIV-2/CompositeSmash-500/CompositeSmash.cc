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

class CompositeSmash {

  public:
     int notprime(int N)
     {
        if(N<2)
           return 0;
        int counter=0;
        int d=N;
        for(int i=2;i<N;i++)
        {
           if(d<i)
              break;
           while(d%i==0)
           {
              d=d/i;
              counter++;
           }
        }
        return counter;
     }
     bool test(int tar,int r)
     {
        double ss = sqrt(tar);
        int sq = (int)ss;
        cout<<sq<<endl;
        if(sq*sq!=tar)
           return false;
        while(r%sq==0 && r!=1)
        {
           r/=sq;
        }
        cout<<"r="<<r<<endl;
        if(r==1)
           return true;
        else
           return false;
     }
     string thePossible(int N, int target) {
             if(N==target)
                return "Yes";
             if(target>N||N%target!=0)
                return "No";
             int r=N/target;
             int a = notprime(target);
             //int b = notprime(r);
             cout<<"HERE?"<<endl;
             if(a==0)
		return "Yes";
	     if(a==2 && test(target,r))
	        return "Yes";
	     return "No";
	}

};
