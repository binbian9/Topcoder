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

class ComparerInator {

  public: 
     int testa(int a,int b)
     {
        b = a+b;
        return a;
     }
     int testb(int a,int b)
     {
        a+=b;
        return b;
     }
     int testc(int a,int b)
     {
        return a<b?a:b;
     }
     int testd(int a,int b)
     {
        return a<b?b:a;
     }
     int makeProgram(vector <int> A, vector <int> B, vector <int> wanted) {
             int size = A.size();
             int ans[4]={0};
             for(int i=0;i<size;i++)
             {
                if(wanted[i]==testa(A[i],B[i]))
                   ans[0]++;
                if(wanted[i]==testb(A[i],B[i]))
                   ans[1]++;
                if(wanted[i]==testc(A[i],B[i]))
                   ans[2]++;
                if(wanted[i]==testd(A[i],B[i]))
                   ans[3]++;
             }
            if(ans[0]==size||ans[1]==size)
                return 1;
            else if(ans[2]==size||ans[3]==size)
               return 7;
            return -1;
	}

};
