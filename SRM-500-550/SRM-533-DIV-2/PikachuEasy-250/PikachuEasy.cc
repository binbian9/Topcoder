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

class PikachuEasy {

  public: string check(string word) {
             int size = word.length();
             for(int i=0;i<50;i++)
             {
                unsigned int zzz = word.find("pi");
                if(zzz<500)
                   word.replace(zzz,2,"__");
                zzz = word.find("ka");
                if(zzz<500)
                   word.replace(zzz,2,"__");
                zzz=word.find("chu");
                if(zzz<500)
                   word.replace(zzz,3,"___");
             }

             for(int i=0;i<size;i++)
             {
                if(word[i]!='_')
                   return "NO";
             }
		return "YES";
	}

};
