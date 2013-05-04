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

class AkariDaisukiDiv2 {

  public: int countTuples(string S) {
             int size = S.length();
             int counter=0;
         
             map< vector<string>, int> m;
             map< vector<string>, int>::iterator iter;
             for(int i=1;i<size;i++)
             {
                for(int j=1;j<size;j++)
                {
                   for(int k=1;k<size;k++)
                   {
                      for(int l=1;l<size;l++)
                      {
                         for(int m=1;m<size;m++)
                         {
                            if(i+j+k+l+m < size)
                               continue;
                            else if(i+j+k+l+m >size)
                               break;
                            else
                            {
                               string a=S.substr(0,i);
                               string b=S.substr(i,j);
                               string c=S.substr(i+j,k);
                               string d=S.substr(i+j+k,l);
                               string e=S.substr(i+j+k+l,m);
                               if(b==d)
                               {
                                  vector<string> v;
                                  v.push_back(S.substr(0,i));
                                  v.push_back(S.substr(i+1,j));
                                  v.push_back(S.substr(i+j+1,k));
                                  v.push_back(S.substr(i+j+k+1,l));
                                  v.push_back(S.substr(i+j+k+l+1,m));
                                  //cout<<"a="<<a<<",b="<<b<<",c="<<c<<",d="<<d<<",e="<<e<<endl;
                                  //cout<<"sum="<<i+j+k+l+m<<endl;
                                 //iter=m.find(v);
                                 //if(iter==m.end())
                                    //m[v]=1;
                                    counter++;
                                 
                               }
                             }
                         }
                      }
                   }
                }
             }
		return counter;
	}

};
