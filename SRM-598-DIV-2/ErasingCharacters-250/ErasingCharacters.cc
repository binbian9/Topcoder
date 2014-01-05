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

class ErasingCharacters {

  public: string simulate(string s) {
             int size = s.length();
             string temp = s;
             while(1)
             {
                size = temp.length();
                int i=0;
                for(i=0;i<size;i++)
                {
                   if(i<size-1)
                   {
                      if(temp[i]==temp[i+1])
                         break;
                   }
                }
                cout << "i="<<i<<endl;
                if(i==size)
                   break;
                else
                {
                   string zz = temp.substr(0,i);
                   cout<<"@ zz = "<<zz<<endl;
                   if(i + 2 <size)
                   {
                      cout<<"substr = "<<temp.substr(i+2)<<endl;
                      temp=zz+temp.substr(i+2);
                   }
                   else
                      temp = zz;
                }
                cout<<"temp = "<<temp<<endl;
             }

		return temp;
	}

};
