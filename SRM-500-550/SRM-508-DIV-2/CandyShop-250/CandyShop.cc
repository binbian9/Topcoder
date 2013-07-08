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

class CandyShop {

  public: 
     map<string,int> m;
     map<string,int>::iterator iter;
     int size;
     int array[401][401];
     void addk(int x,int y)
     {
        
        stringstream ss;
        ss<<x<<","<<y;
        string s = ss.str();
        iter = m.find(s);
        if(iter==m.end())
           m[s]=1;
        else
           m[s]++;
           
        return ;
     }
     int countProbablePlaces(vector <int> X, vector <int> Y, vector <int> R) {
             size = X.size();
             memset(array,0,sizeof(array));
             for(int i=0;i<size;i++)
             {
                //addk(X[i],Y[i]);
                array[X[i]+200][Y[i]+200]++;
                for(int j=-R[i];j<=R[i];j++)
                {
                   for(int k=-R[i];k<=R[i];k++)
                   {
                      if(j+k>R[i])
                         break;
                      if(j==0 && k==0 || (abs(j)+abs(k))>R[i])
                         continue;
                      //addk(X[i]+j,Y[i]+k);
                      array[X[i]+j+200][Y[i]+k+200]++;
                   }
                }
             }
             int c = 0;
             for(int i=0;i<=400;i++)
             {
                for(int j=0;j<=400;j++)
                   if(array[i][j]==size)
                     c++;
             }
		return c;
	}

};
