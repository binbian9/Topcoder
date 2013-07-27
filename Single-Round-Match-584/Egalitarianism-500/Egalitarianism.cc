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

class Egalitarianism {

  public: 
     struct ddd{
        int val;
        int dep;
     };
     int maxDifference(vector <string> isFriend, int d) {
             vector<int> v[51];
             int row = isFriend.size();
             int col = isFriend[0].length();

             for(int i=0;i<row;i++)
             {
                for(int j=i+1;j<col;j++)
                {
                   if(isFriend[i][j]=='Y')
                   {
                      v[i].push_back(j);
                      v[j].push_back(i);
                   }
                }
             }
             int deepest=0;
             int visit[51]={0};
             int count = 0;
             struct ddd store[51];
             for(int i=0;i<row;i++)
             {
                if(visit[i])
                   continue;
                else
                   count ++;
                cout<<"i="<<i<<endl;
                struct ddd ts;
                ts.dep = 0;
                ts.val = i;
                store[i] = ts;
                vector<struct ddd> stack;
                stack.push_back(ts);
                while(!stack.empty())
                {
                   struct ddd temp;
                   temp = stack.back();
                   cout<<"temp="<<temp.val<<endl;
                   stack.pop_back();
                   if(visit[temp.val])
                      continue;
                   visit[temp.val]=1;
                   int sz = v[temp.val].size();
                   for(int j=0;j<sz;j++)
                   {
                      struct ddd tts;
                      tts.val = v[temp.val][j];
                      tts.dep = temp.dep+1;
                      store[temp.val] = tts;
                      deepest = max(deepest,tts.dep);
                      cout<<"DEP="<<tts.dep<<endl;
                      stack.push_back(tts);
                   }
                }
             }
             bool change = true;
             while(change)
             {
                change = false;
                for(int i=0;i<row;i++)
                {
                   int sssz = v[i].size();
                   for(int j=0;j<sssz;j++)
                   {
                      if(abs(store[i].dep - store[j].dep)>1)
                      {
                         if(store[i].dep>store[j].dep)
                            store[i].dep=store[j].dep+1;
                         else
                            store[j].dep=store[i].dep+1;
                         change = true;
                      }
                   }
                }
             }
             for(int i=0;i<row;i++)
             {
                cout<<"DEEP="<<store[i].dep<<endl;
             }
             //cout<<"deep="<<deepest<<endl;
             if(count<2)
		return (deepest-1)*d;
             else
                return -1;
	}

};
