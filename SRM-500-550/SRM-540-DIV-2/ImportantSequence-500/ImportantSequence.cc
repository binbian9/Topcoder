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

class ImportantSequence {

  public: int getCount(vector <int> B, string operators) {
             int size = B.size();
             int counter=0;
             for(int i=1;i<10000000;i++)
             {
                int c=0;
                int prev=i;
                while(c<size)
                {
                   if(operators[c]=='-')
                      prev=prev-B[c];
                   else if(operators[c]=='+')
                      prev=B[c]-prev;
                   //cout<<"prev="<<prev<<endl;
                   if(prev<=0)
                      break;
                   c++;
                   if(c==size)
                   {
                      counter++;
                      //cout<<"i="<<i<<endl;
                   }
                }
             }
             if(counter>9999997)
                return -1;
             else
		return counter;
	}

};
