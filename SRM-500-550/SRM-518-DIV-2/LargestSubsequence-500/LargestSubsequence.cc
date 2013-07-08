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

class LargestSubsequence {

  public: string getLargest(string s) {
             int size = s.length();
             int pos1,pos2;
             pos1=s[0];
             pos2=0;
             int index=0;
             stringstream ss;
             while(index<size)
             {
                pos1=s[index]-'a';
                pos2=index;
               for(int i=index+1;i<size;i++)
               {
                  int temp = s[i]-'a';
                  if(pos1<temp)
                  {
                     pos1=temp;
                     pos2 = i;
                  }
               }
               ss<<s[pos2];
               index = pos2+1;
             }
		return ss.str();
	}

};
