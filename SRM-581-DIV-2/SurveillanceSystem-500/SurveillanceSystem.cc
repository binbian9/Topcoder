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

class SurveillanceSystem {

  public: 
     
     struct area
     {
        int cam_id;
        int start;
     };
     string getContainerInfo(string containers, vector <int> reports, int L) {
             int check[55]={0};
             int cam[55]={0};
             int test[55]={0};
             int rec[55]={0};
             int size = containers.length();
             int sv = reports.size();
             map<int,vector<struct area> > m;
             map<int,vector<struct area> >::iterator iter;
             
             for(int i=0;i<size-L+1;i++)
             {
                int c=0;
                for(int j=0;j<L;j++)
                {
                   if(i+j<size)
                   {
                      if(containers[i+j]=='X')
                         c++;
                   }
                }
                rec[i]=c;
                cout<<c;
                test[rec[i]]++;
             }
             for(int i=size-L+1;i<size;i++)
                rec[i]=51;
             for(int i=0;i<sv;i++)
             {
                cam[reports[i]]++;
             }
             cout<<endl;

             int test_cam[55] = {0};
             for(int k=0;k<sv;k++)
             {
                if(test_cam[reports[k]]==0)
                {
                   test_cam[reports[k]]++;
                  for(int i=0;i<size-L+1;i++)
                  {
                     if(reports[k]==rec[i])
                     {
                        struct area aa;
                        aa.cam_id = rec[i];
                        aa.start = i;
                        m[rec[i]].push_back(aa);
                     }
                  }
                }
             }

             for(iter=m.begin();iter!=m.end();iter++)
             {
                int sss = iter->second.size();
                int id = iter->second[0].cam_id;
                int ccccc[55] = {0};
                for(int i=0;i<sss;i++)
                {
                   int tem = iter->second[i].start;
                   for(int j=0;j<L;j++)
                   {
                      ccccc[tem+j]++;
                   }
                }
                for(int i=0;i<size;i++)
                {
                   if(ccccc[i]+cam[id]>test[id])
                      check[i]=2;
                   else if(check[i]==0 && ccccc[i]>0)
                      check[i]=1;
                }
             }


             stringstream ss;
             for(int i=0;i<size;i++)
             {
                if(check[i]==0)
                   ss<<"-";
                else if(check[i]==1)
                   ss<<"?";
                else
                   ss<<"+";
             }
		return ss.str();
	}

};
