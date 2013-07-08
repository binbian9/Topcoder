#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
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

class TheLotteryBothDivs {

  public: 
     bool cmp(const string &a,const string &b)
     {
        //a is shorter
        int sa = a.length();
        int sb = b.length();
        if(b.substr(sb-sa,sa)==a)
           return true;
        return false;//a.length()<b.length();
     }
     string rv(string a)
     {
        stringstream ss;
        int size = a.length();
        for(int i=0;i<size;i++)
           ss<<a[i];
        return ss.str();
     }
     double find(vector <string> goodSuffixes) {
             int size = goodSuffixes.size();
             for(int i=0;i<size;i++)
             {
                for(int j=i+1;j<size;j++)
                {
                   if(goodSuffixes[i].length()>goodSuffixes[j].length())
                   {
                      //swap(goodSuffixes[i]<goodSuffixes[j]);
                      string temp = goodSuffixes[i];
                      goodSuffixes[i] = goodSuffixes[j];
                      goodSuffixes[j] = temp;
                   }
                }
             }
             //sort(goodSuffixes.begin(),goodSuffixes.end(),cmp);
             vector<string> v;
             //cout<<goodSuffixes[0]<<endl;
             for(int i=size-1;i>=0;i--)
             {
                bool check = true;
                for(int j=i-1;j>=0;j--)
                {
                   if(i==j)
                      continue;

                   if(cmp(goodSuffixes[j],goodSuffixes[i]))
                     check = false;
                   //cout<<"good = " <<goodSuffixes[i]<<" , "<<goodSuffixes[j]<<endl;
                      
                }
                if(check)
                   v.push_back(goodSuffixes[i]);
             }
             long double ans = 0.0;
             size = v.size();
             for(int i=0;i<size;i++)
             {
                cout<<"ans="<<v[i]<<endl;
                int sz = v[i].length();
                ans += pow(0.1,sz);
             }
		return ans;
	}

};
