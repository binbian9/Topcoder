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

class CheatingQuiz {

  public: vector <int> howMany(string answers) {
             int size=answers.length();

             int c=0;
             map<char,int> m;
             map<char,int>::iterator iter;
             vector<int> v;
             for(int i=0;i<size;i++)
             {
                iter = m.find(answers[i]);
                if(iter==m.end())
                {
                   m[answers[i]]=1;
                   c++;
                }
                else
                   m[answers[i]]++;
             }
             for(int i=0;i<size;i++)
             {
                v.push_back(c);
                m[answers[i]]--;
                if(m[answers[i]]==0)
                   c--;
             }
		return v;
	}

};
