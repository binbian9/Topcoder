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

class SentenceCapitalizerInator {

  public: string fixCaps(string paragraph) {
             vector<string> vs;
             unsigned int pos1 = 0;
             unsigned int pos2 = 0;
             while(1)
             {
                pos2 = paragraph.find(".",pos1);
                if(pos2>999)
                   break;
                vs.push_back(paragraph.substr(pos1,pos2-pos1+1));
                pos1 = pos2+1;
             }
             vs.push_back(paragraph.substr(pos1));
             stringstream ss;
             int size = vs.size();
             for(int i=0;i<size;i++)
             {
                //vs[i][0]-=32;
                if(i==0)
                   vs[i][0]-=32;
                else
                   vs[i][1]-=32;
                ss<<vs[i];
             }
		return ss.str();
	}

};
