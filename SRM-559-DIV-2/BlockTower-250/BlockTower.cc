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
     int MM;
     int getTallest(vector <int> blockHeights) {
        MM=0;
        int size = blockHeights.size();
        test1(blockHeights,0,0,false,size);
		return MM;
      }
          void test1(vector<int> bh,int sum,int index,bool isodd,int size)
         {
               if(sum>MM)
                 MM=sum;
               if(index>=size)
                  return;
    
               if(!isodd)
                  if(bh[index]%2==0)
                     test1(bh,sum+bh[index],index+1,false,size);
                  else
                  {
                     test1(bh,sum+bh[index],index+1,true,size);
                     test1(bh,sum,index+1,false,size);
                  }
                  else
                  {
                     if(bh[index]%2==1)
                         test1(bh,sum+bh[index],index+1,true,size);
                     else
                         test1(bh,sum,index+1,true,size);
                  }
         }

};
