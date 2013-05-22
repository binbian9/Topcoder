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

class UndoHistory {

  public: int minPresses(vector <string> lines) {
             int size = lines.size();
             map<string,int> m;
             map<string,int>::iterator iter;
             int keys=0;
             int index=0;
             string s="__SDF#GSAG##%@";
             for(int i=0;i<size;i++)
             {
                if(i!=0)
                {
                  unsigned int test = 99999;
                  test = lines[i].find(lines[i-1]);
                
                  if(test>50000)
                     keys+=2;
                }
                  for(iter=m.begin();iter!=m.end();iter++)
                  {
                      unsigned int temp = lines[i].find(iter->first);
                     if(temp==0 && index < iter->second)
                     {
                         index = iter->second;
                        s=iter->first;
                     }
                   }
                  cout<<"index="<<index<<endl;
                  keys+=(int)lines[i].length()-index;
                  for(int j=index;j<(int)lines[i].length();j++)
                  {
                     iter = m.find(lines[i].substr(0,j+1));
                     if(iter==m.end())
                     {
                        cout<<lines[i].substr(0,j+1)<<endl;
                         m[lines[i].substr(0,j+1)]=j+1;
                     }
                  }
                
                keys++;
                cout<<"keys="<<keys<<endl;
             }
		return keys;
	}

};
