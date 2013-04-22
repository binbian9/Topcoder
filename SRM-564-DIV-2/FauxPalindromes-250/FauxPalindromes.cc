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

class FauxPalindromes {

  public: string classifyIt(string word) {
             int size = word.length();
             bool check = true;
             for(int i=0;i<size/2;i++)
             {
                if(word[i]!=word[size-1-i])
                {
                     check = false;
                     break;
                }
             }
             if(check)
               return "PALINDROME";
             char a = word[0];
             stringstream ss;
             ss<<a;
             for(int i=1;i<size;i++)
             {
                if(a!=word[i])
                {
                   ss<<word[i];
                   a=word[i];
                }
             }
             string s = ss.str();
             size = s.length();
             for(int i=0;i<size;i++)
             {
                if(s[i]!=s[size-1-i])
                {
                   return "NOT EVEN FAUX";
                }
             }
		return "FAUX";
	}

};
