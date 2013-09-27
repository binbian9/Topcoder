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

class LittleElephantAndBooks {

  public: int getNumber(vector <int> pages, int number) {
             int size = pages.size();
             sort(pages.begin(),pages.end());
             int small = 0;
             for(int i=0;i<number;i++)
             {
                small += pages[i];
             }
             int second = 999999;
             for(int j=0;j<number;j++)
             {
               for(int i=number;i<size;i++)
               {
                  int temp = small -pages[j]+pages[i];
                  if(temp<second && temp >small)
                     second = temp;
               }
             }
		return second;
	}

};
