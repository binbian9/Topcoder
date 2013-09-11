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

class NumberMagicEasy {

  public: int theNumber(string answer) {
             if(answer == "NNNN")
                return 16;
             else if (answer == "NNNY")
                return 15;
             else if (answer == "NNYN")
                return 14;
             else if (answer == "NNYY")
                return 13;
             else if (answer == "NYNN")
                return 12;
             else if (answer == "NYNY")
                return 11;
             else if (answer == "NYYN")
                return 10;
             else if (answer == "NYYY")
                return 9;
             else if (answer == "YNNN")
                return 8;
             else if (answer == "YNNY")
                return 7;
             else if (answer == "YNYN")
                return 6;
             else if (answer == "YNYY")
                return 5;
             else if (answer == "YYNN")
                return 4;
             else if (answer == "YYNY")
                return 3;
             else if (answer == "YYYN")
                return 2;
             else 
                return 1;
	}

};
