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

class BadVocabulary {

  public: int count(string badPrefix, string badSuffix, string badSubstring, vector <string> vocabulary) {
             int size = vocabulary.size();
             int sum =0;
             int b = badSuffix.length();
             int c = badSubstring.length();
             for(int i=0;i<size;i++)
             {
                int l = vocabulary[i].length();
                int x = vocabulary[i].find(badPrefix);
                //cout<<"x="<<x<<endl;
                int y = vocabulary[i].find(badSuffix);
                int last = y;
                while(y>=0)
                {
                   last = y;
                   y=vocabulary[i].find(badSuffix,last+1);
                }
                //cout<<"last="<<last<<endl;
                if(x==0)
                {
                   cout<<vocabulary[i]<<" X="<<x<<endl;
                   sum++;
                   continue;
                }
                if(last>=0 && last==l-b)
                {
                   cout<<vocabulary[i]<<" Y="<<last<<endl;
                   sum++;
                   continue;
                }
                int pos = vocabulary[i].find(badSubstring);
                while(pos>=0)
                {
                   last = pos;
                   if(pos!=0 && pos!=l-c)
                   {
                      cout<<"l-b="<<l-c<<endl;
                      cout<<vocabulary[i]<<" pos="<<pos<<endl;
                      sum++;
                      break;
                   }
                   pos = vocabulary[i].find(badSubstring,last+1);
                }
                //cout<<"pos="<<pos<<" sum="<<sum<<endl;
                //if(pos<1000 && pos>=0 && pos!=0 && pos!= l-b)
                   //sum++;

             }
		return sum;
	}

};
