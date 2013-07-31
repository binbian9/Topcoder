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

class StringWeightDiv2 {

  public:
     int MOD(string a,int mod)
     {
        int len = a.length(),i;
        long long int t = 0;
        for(i=0;i<len;i++)
        {
           t*=10;
           t+=a[i]-'0';
           if(t>=mod)
              t=t%mod;
        }
        return t;
     }
     
     string multiply(string a,string b)
     {
        int i,j,ca,cb,*s;
        stringstream c;
        ca = a.length();
        cb = b.length();
        s = (int*)malloc(sizeof(int)*(ca+cb));
        for(i=0;i<ca+cb;i++)
           s[i]=0;
        for(i=0;i<ca;i++)
           for(j=0;j<cb;j++)
              s[i+j+1]+=(a[i]-'0')*(b[j]-'0');
        for(i=ca+cb-1;i>=0;i--)
           if(s[i]>=10)
           {
              s[i-1]+=s[i]/10;
              s[i]%=10;
           }
        i=0;
        while(s[i]==0)
           i++;
        for(j=0;i<ca+cb;i++,j++)
           c<<s[i];
        free(s);
        return c.str();
     }
     
     int countMinimums(int L) {
             long long v[1001]={0};
             v[0]=1;
             for(int i=1;i<=26;i++)
             {
                stringstream a;
                stringstream b;
                a<<v[i-1];
                b<<26-i+1;
                string te = multiply(a.str(),b.str());
                v[i] = MOD(te,1000000009);
                //vi[i]=(v[i-1]*(26-i+1))%1000000009;
                if(v[i]<0)
                   cout<<"v[i] OVERFLOW!!! = "<<i<<endl;
             }
             if(L<27)
                return v[L];
             /*
             for(int i=27;i<=L;i++)
             {
                long long temp = 0;
                for(int j=1;j<=i-26;j++)
                   temp = (temp + v[j])%1000000009;
                v[i]=(v[i-1]*(temp))%1000000009;
                if(v[i]<0)
                   cout<<"v[i] OVERFLOW!!! = "<<i<<endl;
             }
             cout<<v[L-1]<<endl;
             cout<<v[L]<<endl;
             */
             int num = L-26;
             long long ans = v[26];
             long long sum = 0;
             for(int i=1;i<=num;i++)
             {
                sum = (sum+(long long)v[i])%1000000009;
                cout<<sum<<endl;
             }
             stringstream a;
             stringstream b;
             a<<sum;
             b<<ans;
             string ss = multiply(a.str(),b.str()); 
             ans = MOD(ss,1000000009);
	     return ans;
	}

};
