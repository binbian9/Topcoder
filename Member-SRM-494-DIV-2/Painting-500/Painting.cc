#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <utility>
#include <iomanip>
#include <cmath>
#include <ctime>

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

class Painting {

  public: 
     int N,M;
     int f[50][50];
     int z[50][50];
     bool check(int level){
        for(int i=0;i<N;i++)
           for(int j=0;j<M;j++)
              z[i][j]=0;
        for(int i=0;i+level<=N;i++)
        {
           for(int j=0;j+level<=M;j++)
           {
              bool flag = true;
              if(f[i][j]==1)
              {
                 for(int k=i;k<i+level && flag;k++ )
                    for(int l=j;l<j+level && flag;l++)
                       if(f[k][l]==0)
                          flag = false;
              if(flag)
                 for(int k=i;k<i+level;k++)
                    for(int l=j;l<j+level;l++)
                       z[k][l]=1;
              }
           }
        }
        for(int i=0;i<N;i++) {
           for(int j=0;j<M;j++){
              if(f[i][j]!=z[i][j])
                 return false;
           }
        }
        return true;
     }
     
     int largestBrush(vector <string> picture) {
             N = picture.size();
             M = picture[0].length();
             for(int i=0;i<N;i++)
                for(int j=0;j<M;j++)
                   if(picture[i][j]=='B')
                      f[i][j]=1;
                   else
                      f[i][j]=0;
             int L = 1;
             int R = min(M,N);
             while(L<R)
             {
                int mid = (L+R+1)>>1;
                if(check(mid))
                   L = mid;
                else
                   R = mid-1;
                mid = (L+R+1)>>1;
             }
             cout<<"L="<<L<<" R="<<R<<endl;
		return L;
	}

};
