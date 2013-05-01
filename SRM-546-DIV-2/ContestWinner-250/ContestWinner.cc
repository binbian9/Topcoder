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

class ContestWinner {

  public: 
     struct a{
        int counter;
        int index;
        int who;
     
     bool operator<(const a& bb) const
     {
        if(counter!=bb.counter)
           return counter>bb.counter;
        else
           return index<bb.index;
     }
     };

     int getWinner(vector <int> events) {
             int size=events.size();
             map<int,struct a> m;
             map<int,struct a>::iterator iter;
             int mm=0;
             for(int i=0;i<size;i++)
             {
                struct a aaa;
                iter = m.find(events[i]);
                if(iter==m.end())
                {
                   aaa.who=events[i];
                   aaa.counter = 1;
                   aaa.index = i;
                   m[events[i]]=aaa;
                   cout<<"who?="<<m[events[i]].who<<endl;
                }
                else
                {
                   m[events[i]].counter++;
                   m[events[i]].index=i;
                   
                }
                if(m[events[i]].counter>mm)
                   mm=m[events[i]].counter;
             }
             vector<struct a> v;
             size = m.size();
             int i=0;
             for(iter=m.begin();iter!=m.end();iter++)
             {
                struct a zzz=iter->second;
                v.push_back(zzz);
                cout<<v[i].who<<endl;
                i++;
             }
             sort(v.begin(),v.end());


		return v[0].who;
	}

};
