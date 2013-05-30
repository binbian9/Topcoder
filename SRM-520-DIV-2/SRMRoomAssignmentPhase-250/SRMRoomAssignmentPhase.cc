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

class SRMRoomAssignmentPhase {

  public: int countCompetitors(vector <int> ratings, int K) {
             int size = ratings.size();
             int me = ratings[0];
             sort(ratings.rbegin(),ratings.rend());
             int index=0;
             vector<int> v[50];
             int sk=0;
             for(int i=0;i<size;i++)
             {
                if(ratings[i]==me)
                   index = sk;
                v[sk].push_back(ratings[i]);
                sk++;
                if(sk==K)
                   sk=0;
             }
             size = v[index].size();
             int counter=0;
             for(int i=0;i<size;i++)
             {
                if(v[index][i]!=me)
                {
                   counter++;
                }
                else
                   break;
             }
             return counter;

	}

};
