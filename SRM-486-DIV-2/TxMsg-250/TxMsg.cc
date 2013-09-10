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

class TxMsg {

  public: 
     vector<string> cal(string s){
        //int size = s.length();
        vector<string> v;
        int pos1,pos2;
        pos1=pos2=0;
        pos2 = s.find(" ",pos1);
        while(pos2>=0 && pos2<=1000)
        { 
           v.push_back(s.substr(pos1,pos2-pos1));
           cout<<s.substr(pos1,pos2-pos1)<<endl;
           pos1 = pos2+1;
           pos2 = s.find(" ",pos1);
           cout<<"pos2="<<pos2<<endl;
           //cout<<s.substr(pos1,pos2-pos1)<<endl;
        }
        cout<<s.substr(pos1)<<endl;
        v.push_back(s.substr(pos1));
        return v;
     }
     string getMessage(string original) {
             //int size = original.length();

             vector<string> v = cal(original);
		return "tet";
	}

};
