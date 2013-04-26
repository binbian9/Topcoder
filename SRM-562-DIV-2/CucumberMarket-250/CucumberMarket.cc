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

class CucumberMarket {

   string ans;
   int bd;
   void sum(vector<int> price, int index, int k,int s,int counter)
   {
      int size = price.size();
      if(counter==k)
      {
         if(s>bd)
            ans = "NO";
         return;
      }
      if(index==size)
         return;
      sum(price, index+1,k,s+price[index],counter+1);

      sum(price, index+1,k,s,counter);
   }
  public: string check(vector <int> price, int budget, int k) {
             ans = "YES";
             bd = budget;
             sum(price,0,k,0,0);

		return ans;
	}

};
