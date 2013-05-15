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

class DengklekMakingChains {

  public: 
     int M;
     void con(int counter,vector<string> chains,int index,vector<bool> check,string s)
     {
        int size=chains.size();
        if(check[index])
           return;
        check[index]=true;
        s+=chains[index];
        if(counter==size)
        {
           //cout<<s<<endl;
           int value[10050]={0};
           for(int i=1;i<size*3+1;i++)
           {
              if(s[i-1]=='.')
                 value[i]=0;
              else
              {
                 value[i]=s[i-1]-'0';
                 value[i]+=value[i-1];
              }
              M=max(M,value[i]);
           }
        }
        else
        {
           for(int i=1;i<size;i++)
           {
               con(counter+1,chains,(index+i)%size,check,s);
           }
        }


     }
     struct jew{
        int index;
        int tail;
        int head;
     };
     int maxBeauty(vector <string> chains) {
             int size = chains.size();
             M=0;
             if(size==1)
             {
                int temp=0;
                for(int i=0;i<3;i++)
                {
                   if(chains[0][i]!='.')
                   {
                     int now = chains[0][i]-'0';
                     temp = now+temp;
                     M=max(temp,M);
                   }
                   else
                      temp =0;
                }
                return M;

             }
             vector<struct jew > v;
             int sum=0;
             int mid=0;
             for(int i=0;i<size;i++)
             {
                struct jew jjj;
                jjj.index=i;
                int a=3;
                int b=0;
                int t=chains[i][0]-'0';
                int u=chains[i][1]-'0';
                int q=chains[i][2]-'0';
                int d=0;
                int e=0;
                for(int j=0;j<3;j++)
                {
                   if(chains[i][j]=='.')
                   {
                      a--;
                      d=j;
                   }
                   else
                   {
                      b=j;
                      e=j;
                   }
                }
                if(a==3)
                {
                   sum=sum+t+u+q;
                }
                else if(a==1)
                {
                   if(e==0)
                   {
                      jjj.tail=t;
                      jjj.head=0;
                      v.push_back(jjj);
                   }
                   else if(e==1)
                   {
                      mid=max(mid,u);
                   }
                   else if(e==2)
                   {
                      jjj.tail=0;
                      jjj.head = q;
                      v.push_back(jjj);
                   }

                }
                else if(a==2)
                {
                   if(d==0)//head
                   {
                      jjj.head=u+q;
                      jjj.tail=0;
                      v.push_back(jjj);
                   }
                   else if(d==1)
                   {
                      jjj.head=q;
                      jjj.tail=t;
                      v.push_back(jjj);
                   }
                   else if(d==2)
                   {
                      jjj.head=0;
                      jjj.tail=t+u;
                      v.push_back(jjj);
                   }
                }
             } 

             int sssss=v.size();
             int plus=0;
             for(int i=0;i<sssss;i++)
             {
                plus=max(max(v[i].tail,v[i].head),plus);
                for(int j=i+1;j<sssss;j++)
                {
                   //cout<<"v[i].tail="<<v[i].tail<<" v[i].head="<<v[i].head<<endl;
                   //cout<<"v[j].tail="<<v[j].tail<<" v[j].head="<<v[j].head<<endl;
                   plus=max(max(v[i].tail+v[j].head,v[j].tail+v[i].head),plus);
                }
             }
             cout<<"sum="<<sum<<endl;
             cout<<"plus="<<plus<<endl;
             /*
             vector<bool> check;
             for(int i=0;i<999;i++)
                check.push_back(false);
             for(int i=0;i<size;i++)
             {
               con(1,chains,i,check,"");
               cout<<i<<endl;
             }
             */
		return max(plus+sum,mid);
	}

};
