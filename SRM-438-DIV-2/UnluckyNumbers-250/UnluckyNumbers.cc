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

class UnluckyNumbers {

  public: int getCount(vector <int> luckySet, int n) {
             int size = luckySet.size();
             sort(luckySet.begin(),luckySet.end());
             pair<int,int> p[51];
             int start = 1;
             int ans=0;
             for(int i=0;i<size;i++)
             {
                p[i].first = start;
                p[i].second = luckySet[i]-1;
                int j = n-p[i].first;
                int length = p[i].second - p[i].first +1;
                if(n>=p[i].first && n<=p[i].second)
                {
                   ans = j*(length-j);
                   ans += length-j-1;
                   break;
                }

                start = luckySet[i]+1;
             }
             return ans;

	}

};
