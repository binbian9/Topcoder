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

class UnluckyIntervals {



   string multiply(string a,string  b)
   {
          int i,j,ca,cb,* s;
          stringstream c;
          ca=a.length();
          cb=b.length();
          s=(int*)malloc(sizeof(int)*(ca+cb));
          for (i=0;i<ca+cb;i++)
              s[i]=0;
          for (i=0;i<ca;i++)
              for (j=0;j<cb;j++)
                  s[i+j+1]+=(a[i]-'0')*(b[j]-'0');
          for (i=ca+cb-1;i>=0;i--)
              if (s[i]>=10)
              {
                  s[i-1]+=s[i]/10;
                  s[i]%=10;
              }
              i=0;
              while (s[i]==0)
                  i++;
              for (j=0;i<ca+cb;i++,j++)
                  c<<s[i];
              free(s);
          return c.str();
   }

   struct keyInfo
   {
        string Key1;  
        bool operator<(const keyInfo& A) const
        {
           if(Key1.length()!=A.Key1.length())
               return Key1.length()<A.Key1.length(); 
           else
               return Key1<A.Key1;
        }
   };
   bool comp(const string a,const string b)
   {
      if(a.length()!=b.length())
         return a.length()<b.length() ;
      else
         return a<b;
   } 

  public: vector <int> getLuckiest(vector <int> luckySet, int n) {
           int size = luckySet.size();
           cout<<"TEST = "<<multiply("11","11")<<endl;
           map<struct keyInfo,vector<int> > m;
           map<struct keyInfo,vector<int> >::iterator iter;
           //vector<int> ans;
           pair<int,int> interval[51];
           int start = 1;
           for(int i=0;i<size;i++)
           {
              keyInfo kk;
              kk.Key1 = "0";
              m[kk].push_back(luckySet[i]);
              interval[i].first = start;
              interval[i].second = luckySet[i]-1;
              start = luckySet[i]+1;
           }
           for(int i=0;i<size;i++)
           {
              int length = interval[i].second-interval[i].first+1;
              int ccc = 0;
              for(int j=0;j<(length+1)/2;j++)
              {
                 keyInfo kk;
                 //right end
                 //unsigned LL sum = (j+1)*(length-j);
                 stringstream ss;
                 ss<<j+1;
                 stringstream ss2;
                 ss2<<length-j;
                 kk.Key1 = multiply(ss.str(),ss2.str());
 
                 //sum += (length-j)%99999999;
                 m[kk].push_back(interval[i].first+j);
                 //cout<<"sum = "<<sum<<" push back = "<<interval[i].first+j<<endl;
                 if(interval[i].first+j!=interval[i].second-j)
                 {

                     //cout<<"sum = "<<sum<<" push back = "<<interval[i].second-j<<endl;
                     m[kk].push_back(interval[i].second-j);
                     ccc--;
                 }
                 ccc+=2;
                 if(ccc>n)
                    break;
              }
           }
           vector<int> temp;
           for(iter=m.begin();iter!=m.end();iter++)
           {
              sort(iter->second.begin(),iter->second.end());
              for(int i=0;i<iter->second.size();i++)
              {
                 temp.push_back(iter->second[i]);
                 cout<<"iter = "<<iter->second[i]<<endl;
              }
           }
           if(temp.size()<n)
           {
              int ttt = n-temp.size();
              cout<<"tempsize = "<<temp.size()<<endl;
              for(int i=0;i<ttt;i++)
              {
                 cout<<luckySet[size-1]+i+1<<endl;
                 temp.push_back(luckySet[size-1]+i+1);
              }

           }
           vector<int> ans(temp.begin(),temp.begin()+n);



		return ans;

	}

};






