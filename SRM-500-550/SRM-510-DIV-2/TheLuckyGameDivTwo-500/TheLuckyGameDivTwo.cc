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

class TheLuckyGameDivTwo {

  public: 
     int checkluck(int a)
     {
        stringstream ss;
        ss<<a;
        string s = ss.str();
        int size = s.length();
        int c=0;
        for(int i=0;i<size;i++)
        {
           if(s[i]=='4' || s[i]=='7')
              c++;
        }
        if(c==size)
           return 1;
        return 0;
     }
     int find(int a, int b, int jLen, int bLen) {
             int max_opt=0;
             int array[4800]={0};
             for(int i=a-1;i<=b;i++)
                array[i]=-1;
             for(int i=a;i<=b-jLen+1;i++)
             {
                int min_opt=MAX;
                for(int j=i;j<i+jLen-bLen+1;j++)
                {
                   int lucky = 0;
                   if(array[j]==-1 && array[j-1]!=-1)
                   {
                         int ta = checkluck(j-1);
                         int tb = checkluck(j+bLen-1);
                         array[j]=array[j-1]-ta+tb;
                   }
                   else
                   for(int h=0;h<bLen;h++)
                   {
                     stringstream ss;
                     ss<<(j+h);
                     string s = ss.str();
                     int c=0;
                     int size = s.length();
                     for(int k=0;k<size;k++)
                     {
                        if(s[k]=='4' || s[k]=='7')
                           c++;
                     }
                     if(c==size)
                        lucky++;
                   }
                   if(array[j]==-1)
                      array[j]=lucky;

                  if(array[j]<min_opt)
                  {
                     min_opt = array[j];
                  }
                }
                max_opt=max(max_opt,min_opt);
             }
		return max_opt;
	}

};
