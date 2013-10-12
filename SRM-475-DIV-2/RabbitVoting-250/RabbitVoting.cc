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

class RabbitVoting {

  public: string getWinner(vector <string> names, vector <string> votes) {
             map<string,int> m;
             map<string,int>::iterator iter;
             int size = names.size();
             for(int i=0;i<size;i++)
             {
                cout<<"i="<<i<<endl;
                if(names[i]==votes[i])
                   continue;
                m[votes[i]]++;
                cout<<"m[votes[i]]="<<m[votes[i]]<<endl;
             }
             bool many = false;
             string index = "";
             int M = 0;
             cout<<"TEST"<<endl;
             for(iter=m.begin();iter!=m.end();iter++)
             {
                if(iter->second > M)
                {
                   index = iter->first;
                   M = iter->second;
                   many = false;
                }
                else if(iter->second == M)
                {
                   many = true;
                }

             }
             if(many)
                return "";
             else
		return index;
	}

};
