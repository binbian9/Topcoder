#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

class StockQuotes {
	vector<int> split(string test,char token)
		{
			 vector<int> strvec;
			 string strtemp;

			 string::size_type pos1, pos2;
			 pos2 = test.find(token);
			 pos1 = 0;
			 while (string::npos != pos2)
			 {
				 string temp = test.substr(pos1, pos2 - pos1);
				 strvec.push_back(atoi(temp.c_str()));

				 pos1 = pos2 + 1;
				 pos2 = test.find(token, pos1);
			 }
			 string temp = test.substr(pos1);
			 strvec.push_back(atoi(temp.c_str()));
			 return strvec;
		}

	public: vector<string> report(vector<string> quotes) {
		int i,j,B_B,B_A,B_X,A_X;
		int size = quotes.size();
		vector<int> exch;
		map<int,int> m;
		vector<int> qq[50];
		int e[11]={0};
		int b[11]={0};
		int a[11]={0};
		double s[11] = {0.0};

		for(i=0;i<size;i++)
		{
			qq[i]=split(quotes[i],' ');
		}
		B_B = qq[0][1];
		B_A = qq[0][2];
		B_X = qq[0][0];
		A_X = qq[0][0];
		e[B_X]++;
		a[B_X]=B_A;
		b[B_X]=B_B;
		s[B_X]=B_A-B_B;
		s[10]=B_A-B_B;
		e[10]++;
		for(i=1;i<size;i++)
		{
			//cout<<"before : B_X "<<B_X<<" A_X "<<A_X<<endl;
			bool ch = false;
			a[qq[i][0]]=qq[i][2];
			e[qq[i][0]]++;
			b[qq[i][0]]=qq[i][1];
			s[qq[i][0]]+=qq[i][2]-qq[i][1];
			//cout<<B_X<<endl;
			//cout<<qq[i][1]<<endl;
			//cout<<B_B<<endl;
			//cout<<"B_X "<<B_X<<" A_X"<<A_X<<endl;
			if(B_X==qq[i][0] && B_B != qq[i][1])
			{
				//cout<<"1 B_B changed by "<<qq[i][0] <<" :"<<qq[i][1]<<endl;
				B_B = qq[i][1];
				ch = true;
			}
			else
			{
				if(qq[i][1]>B_B)
				{
					B_X = qq[i][0];
					B_B = qq[i][1];
					ch = true;
				}
			}
			if(A_X==qq[i][0] && B_A!=qq[i][2])
			{
				//cout<<"1 B_A changed by "<<qq[i][0]<<" : "<<qq[i][2]<<endl;
				B_A = qq[i][2];
				ch = true;
			}
			else
			{
				if(qq[i][2]<B_A)
				{
					A_X = qq[i][0];
					B_A = qq[i][2];
					ch = true;
				}
			}

			for(j=0;j<10;j++)
			{
				if(e[j]!=0)
				{
					if(b[j]>B_B)
					{
						//cout<<"2 B_B changed by "<<e[j] <<" :"<<b[j]<<endl;
						B_B=b[j];
						B_X=e[j];
						ch = true;

					}
					if(a[j]<B_A)
					{
						//cout<<"2 B_A changed by "<<e[j] <<" :"<<a[j]<<endl;
						B_A=a[j];
						A_X=e[j];
						ch = true;
					}
				}
			}
			if(ch)
			{
				e[10]++;
				s[10]+=B_A-B_B;
				//cout<<"B_X "<<B_X<<" A_X"<<A_X<<endl;
				//cout<<qq[i][1]<<" "<<qq[i][2]<<endl;
			}
			//cout<<"fater : B_X "<<B_X<<" A_X "<<A_X<<endl;
			//cout<<"=============="<<endl;

		}
		vector<string> ans;
		for(i=0;i<11;i++)
		{
			if(e[i]!=0)
			{
				stringstream ss;
				double temp = s[i]/e[i];
				char zzz[50];
				sprintf(zzz,"%.2f", temp);
				//cout<<zzz<<endl;
				ss<<i<<" "<<e[i]<<" "<<zzz;
				ans.push_back(ss.str());
			}
		}
		return ans;
	}

};
