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

class YetAnotherIncredibleMachine {

  public: 
     int cal(int ia,int ib)
     {
        stringstream sa,sb ;
        sa<<ia;
        sb<<ib;
        string a = sa.str();
        string b = sb.str();
        int az = a.length();
        int bz = b.length();
        int *mu = new int[a.length()+b.length()];
        memset(mu,0,sizeof(int)*(a.length()+b.length()));
        for(int i=0; i<az; i++)
           for(int j=0; j<bz; j++)
              mu[i+j+1] += (a[i]-'0')*(b[j]-'0');

        for(int i=az+bz-1; i>0; i--) {
           if(mu[i]>9) {
              mu[i-1] += mu[i]/10;
              mu[i] %= 10;
           }
        }

        char *c = new char[a.length()+b.length()];
        int i = 0, j = 0;
        while(mu[i]==0) i++;
        while(i<az+bz) c[j++] = mu[i++]+'0';
        c[j] = '\0';
        if(c[0]=='\0') {c[1]='\0'; c[0]='0';}
        free(mu);
        string s(c);
        return MOD(s,1000000009);
     }
     int MOD(string a,int mod)
     {
        int len=a.length(),i;
        long long int t=0;//中间变量，最终存储余数
        for(i=0;i<len;i++)
        {
           t*=10;
           t+=a[i]-'0';
           if(t>=mod)
               t=t%mod;
        }
         return t;
     }
     int countWays(vector <int> platformMount, vector <int> platformLength, vector <int> balls) {
             int size = platformMount.size();
             int nbs = balls.size();

             sort(balls.begin(),balls.end());

             long long ans = 1;
             for(int i=0;i<size;i++)
             {
                int left = min(-10000,platformMount[i]-platformLength[i]);
                int right = 0;
                long long temp = 0;
                for(int j=0;j<=nbs;j++)
                {
                   if(j==nbs)
                      right = 10000;
                   else
                      right = balls[j]-1;
                   int pr = min(platformMount[i]+platformLength[i],right);
                   int pl = max(platformMount[i]-platformLength[i],left);

                   if(pr-pl+1>platformLength[i])
                   {
                      temp += pr-pl+1-platformLength[i];
                   }
                   left = right+2;
                }
                if(temp==0)
                   return 0;
                else
                {
                   ans = cal(max(ans,temp),min(ans,temp));
                }
             }
		return ans;
	}

};
