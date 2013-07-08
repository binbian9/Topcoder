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
#define MAX 2000000000
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

class ThreeTeleports {

  public: 
     vector<int> a,b,c;
     int mintime;
     vector<int> strtoint(string s)
     {
        vector<int> v;
        int temp;
        unsigned int pos1,pos2;
        pos1 = 0;
        pos2 = 0;
        pos1 = s.find(" ");
        while(pos1<999)
        {
            stringstream ss;
            ss<<s.substr(pos2,pos1-pos2);
            ss>>temp;
            v.push_back(temp);
            pos2=pos1+1;
            pos1 = s.find(" ",pos2);
        }
        stringstream ss;
        ss<<s.substr(pos2);
        ss>>temp;
        v.push_back(temp);
        return v;

     }
     void walk(int x,int y,int walks,int Dx,int Dy,int time)
     {
        if(walks==4)
           return;

        int q = time+abs(x-Dx);
        int w = time+abs(y-Dy);
        int e = q+w-time;
        if(q<0 || w<0)
           return;
        if( e>0)
          mintime = min(mintime,e);
        else
           return;
        walk(a[0],a[1],walks+1,Dx,Dy,time+abs(x-a[2])+abs(y-a[3])+10);
        walk(a[2],a[3],walks+1,Dx,Dy,time+abs(x-a[0])+abs(y-a[1])+10);
        walk(b[0],b[1],walks+1,Dx,Dy,time+abs(x-b[2])+abs(y-b[3])+10);
        walk(b[2],b[3],walks+1,Dx,Dy,time+abs(x-b[0])+abs(y-b[1])+10);
        walk(c[0],c[1],walks+1,Dx,Dy,time+abs(x-c[2])+abs(y-c[3])+10);
        walk(c[2],c[3],walks+1,Dx,Dy,time+abs(x-c[0])+abs(y-c[1])+10);
     }
     int shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports) {

                a = strtoint(teleports[0]);
                b = strtoint(teleports[1]);
                c = strtoint(teleports[2]);


                mintime = MAX;
                walk(xMe,yMe,0,xHome,yHome,0);
               
		return mintime;
	}

};
