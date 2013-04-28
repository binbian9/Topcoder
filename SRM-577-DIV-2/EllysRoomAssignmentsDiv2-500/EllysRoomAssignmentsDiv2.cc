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

class EllysRoomAssignmentsDiv2 {

  public: double getProbability(vector <string> ratings) {
             int size = ratings.size();
             vector<int> v;
             int elly=0;
             int room=0;
             bool first=true;
             string all="";
             for(int i=0;i<size;i++)
             {
                string s = ratings[i];
                all+=s;
             }
                unsigned int pos1=0,pos2=0;
                pos2 = all.find(" ",pos1);
                while((pos2<50000))
                  {
                     stringstream ss;
                     ss<<all.substr(pos1,pos2);
                     int k=0;
                     ss>>k;
                     if(first)
                     {
                        elly=k;
                        first=false;
                     }

                     v.push_back(k);

                     pos1=pos2+1;
                     pos2 = all.find(" ",pos1);
                  }
                int k=0;
                stringstream ss;
                ss<<all.substr(pos1,all.length());
                ss>>k;
                v.push_back(k);
               
             
             sort(v.rbegin(),v.rend());
             int s1=v.size();
             int t=0;
             for(t=0;t<s1;t++)
             {
                if(elly==v[t])
                   break;
                   
             }
             room=20;
             int R=0;
             if(s1%room==0)
                R=s1/room;
             else
                R=s1/room +1;
             
             cout<<"R="<<R<<endl;
             cout<<"competitors="<<s1<<endl;
             cout<<"room="<<room<<endl;
             cout<<"elly="<<elly<<endl;
             cout<<"place="<<t<<endl;
             if(t<=room &&R!=1)
                return 0;
             else 
                return 1/(R+0.0);
	}

};
