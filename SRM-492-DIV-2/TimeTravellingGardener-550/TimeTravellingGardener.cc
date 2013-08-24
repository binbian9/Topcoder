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

class TimeTravellingGardener {

  public: 
     struct coordinates{
        int x;
        int y;
     };
     bool cal(int x,int y,int x1,int y1,double m)
     {
        //cout<<"x1="<<x1<<" y1="<<y1<<" x="<<x<<" y="<<y<<" m="<<m<<endl;
        //double ddd = fabs(y-y1-m*(x-x1+0.0));
        //cout<<"fabs="<<ddd<<endl;
        if(fabs(y-y1-m*(x-x1+0.0))<0.000001)
             return true;
        else
             return false;
     }
     bool check(int x,int y,int x1,int y1,double m)
     {
        double yy = m*(x-x1)+y1;
        //cout<<"yy="<<yy<<endl;
        if(yy<-0.00000000001|| yy>y)
           return false;
        return true;
     }
     int determineUsage(vector <int> distance, vector <int> height) {
             int size = height.size();
             int md = 1;
             vector<struct coordinates> v;
             int dis = 0;
             for(int i=0;i<size;i++)
             {
                coordinates ccc;
                ccc.x = dis;
                ccc.y = height[i];
                v.push_back(ccc);
                dis+=distance[i];
             }
             //y-y1 = m(x-x1)
             for(int i=0;i<size;i++)
             {
                for(int j=0;j<size;j++)
                {
                   if(i!=j)
                   {
                      int c = 0;
                      double m;
                      m = (v[i].y-v[j].y+0.0)/(v[i].x-v[j].x);
                      //cout<<"x1="<<v[i].x<<" y1="<<v[i].y<<" m="<<m<<endl;
                      for(int k=0;k<size;k++)
                      {
                         if(!check(v[k].x,v[k].y,v[i].x,v[i].y,m))
                         {
                            c=1;
                            break;
                         }
                         if(cal(v[k].x,v[k].y,v[i].x,v[i].y,m))
                            c++;
                      }
                      //cout<<"c="<<c<<endl;
                      if(c>md)
                         md = c;
                   }
                }
             }
		return size-md;
	}

};
