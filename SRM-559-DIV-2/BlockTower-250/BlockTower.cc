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

class BlockTower {

  public: 
     int getTallest(vector <int> blockHeights) {
             int size = blockHeights.size();
             int a[2501] = {0};
             int b[2501] = {0};
             for(int i=0;i<size;i++)
             {
                int temp = blockHeights[i];
                for(int j=2500;j>=0;j--)
                {
                   if(a[j]>0 && a[j+temp]>0)
                   {
                      a[j+temp]=-temp;
                      cout<<j<<" + "<<temp<<" = "<<temp<<endl;
                   }
                   else if(a[j]>0 && a[j+temp]>0&&a[j+temp]%2==1)
                   {
                      a[j+temp]=-temp;
                      cout<<j<<" + "<<temp<<" = "<<temp<<endl;
                   }

                }
                if(a[temp]==0)
                {
                   a[temp]=temp;
                   cout<<temp<<" = "<<temp<<endl;

                }
                else if(a[temp]>0 && a[temp]%2==1)
                {
                   a[temp]=temp;
                   cout<<temp<<" = "<<temp<<endl;
                }
                for(int j=0;j<2501;j++)
                {
                   if(a[j]<0)
                      a[j]=-a[j];
                }
             }
             int ans=0;
             for(ans=2500;ans>=0;ans--)
             {
                if(a[ans]!=0)
                   break;
             }
             return ans;
	}
};
