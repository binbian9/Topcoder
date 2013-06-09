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

class TrainingCamp {

  public: vector <string> determineSolvers(vector <string> attendance, vector <string> problemTopics) {
             int students = attendance.size();
             int problems = problemTopics.size();
             int days = attendance[0].length();

             vector<string> v;

             for(int i=0;i<students;i++)
             {
                stringstream ss;
                for(int j=0;j<problems;j++)
                {
                   int check = true;
                   for(int k=0;k<days;k++)
                   {
                      if(attendance[i][k]=='-' && problemTopics[j][k]=='X')
                      {
                         check = false;
                         break;
                      }
                   }
                   if(check)
                      ss<<"X";
                   else
                      ss<<"-";
                }
                v.push_back(ss.str());
             }
		return v;
	}

};
