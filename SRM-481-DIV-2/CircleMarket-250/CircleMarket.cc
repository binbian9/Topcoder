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

class CircleMarket {

  public: int makePurchases(vector <int> openTime, vector <int> closeTime, int travelTime) {
             int size = openTime.size();
             int mm = 0;
             for(int i=0;i<size;i++)
             {
                if(closeTime[i]>mm)
                   mm = closeTime[i];
             }
             int index = 0;
             int c = 0;
             int array[51]={0};
             for(int i=0;i<=mm;i+=travelTime)
             {
                if(array[index]==0 && i>=openTime[index] && i<=closeTime[index])
                {
                   c++;
                   array[index]++;
                   cout<<"i="<<i<<" index="<<index<<endl;
                }
                index = (index+1)%size;
                //cout<<"i="<<i<<endl;
                if(c==size)
                   break;
             }
		return c;
	}

};
