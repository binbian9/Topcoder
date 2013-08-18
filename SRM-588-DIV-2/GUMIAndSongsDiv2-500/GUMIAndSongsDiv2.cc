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

class GUMIAndSongsDiv2 {

  public: 
     struct sing{
        int tone;
        int time;
        bool operator<(const sing& a ) const {
            if(tone+time<a.tone+a.time)
               return true;
            else if(tone+time>a.tone+a.time)
               return false;
            else
               return tone<a.tone;
        }
     };
     int maxSongs(vector <int> duration, vector <int> tone, int T) {
            vector<struct sing> v;
            int size = tone.size();
            for(int i=0;i<size;i++)
            {
               struct sing s;
               s.tone = tone[i];
               s.time = duration[i];
               v.push_back(s);
            }
            sort(v.begin(),v.end());
            int sum =0;
            for(int i=0;i<size;i++)
            {
               if(i!=size-1 && T - v[i].time - v[i].tone<0)
                  break;
               else if(i!=size-1 && T - v[i].time - v[i].tone>=0)
                  T = T - v[i].time - v[i].tone;
               else if(i==size-1 && T - v[i].time <0)
                  break;
               else 
                  T = T - v[i].time;
               sum++;
            }
	    return sum;
	}

};
