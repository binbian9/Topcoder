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

class ArcadeManao {

   struct s{
      int level;
      int left;
      int right;
      bool money;
   };
  public: int shortestLadder(vector <string> level, int coinRow, int coinColumn) {
             int row = level.size();
             int col = level[0].length();
             cout<<"ROW = "<<row<<" COL="<<col<<endl;
             vector<struct s> v;
             vector<struct s>::iterator iter;
             for(int i=0;i<row;i++)
             {
                bool check = false;
                struct s qq;
                qq.money = false;
                for(int j=0;j<col;j++)
                {
                   if(level[i][j]=='X')
                   {
                      if(!check)
                      {
                        qq.level = i;
                        qq.left = j;
                        check = true;
                      }
                      if(coinRow == i+1 && coinColumn == j+1)
                         qq.money = true;
                      qq.right = j;

                   }
                   else if(check && level[i][j]!='X')
                   {
                      v.push_back(qq);
                      check = false;
                      qq.money = false;
                   }
                }
                if(check && level[i][col-1]=='X')
                {
                   v.push_back(qq);
                }
             }
             int ladder = 0;
             int vz = v.size();
             cout<<"vz = "<<vz<<endl;
             while(ladder <= row)
             {
                cout<<ladder<<endl;
                bool change = true;
                bool cc[51] = {0};
                while(change)
                {
                   change = false;
                   cc[vz-1]=true;
                   for(int i=0;i<vz;i++)
                   {
                      for(int j=i+1;j<vz;j++)
                      {
                         if(((v[i].left>=v[j].left && v[i].left<=v[j].right)||(v[j].left>=v[i].left&&v[j].left<=v[i].right)) && (abs(v[i].level - v[j].level)<=ladder))
                         {
                            if(cc[i]^cc[j])
                           {
                              cc[i] = true;
                              cc[j] = true;
                              change = true;
                           }
                         }
                      }
                   }
                }
                for(int i=0;i<vz;i++)
                {
                   if(cc[i] && v[i].money)
                      goto out;
                   cc[i]=false;
                }
                ladder ++;
             }
out:
		return ladder;
	}

};
