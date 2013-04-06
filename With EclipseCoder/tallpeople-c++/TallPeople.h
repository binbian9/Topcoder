#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

class TallPeople {

	vector<int> ppl[50];
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
			 strvec.push_back((int)temp[0]-'0');

			 pos1 = pos2 + 1;
			 pos2 = test.find(token, pos1);
		 }
		 string temp = test.substr(pos1);
		 strvec.push_back((int)temp[0]-'0');
		 return strvec;
	}
	public: vector<int> getPeople(vector<string> people) {
		int row_size = people.size();

		int i,j;
		for(i=0;i<row_size;i++)
		{
			ppl[i]=split(people[i],' ');
		}
		int col_size = ppl[0].size();
		int col_tall[50]={0};
		int row_short[50]={0};
		for(i=0;i<row_size;i++)
			row_short[i]=99999;
		for(i=0;i<row_size;i++)
		{
			for(j=0;j<col_size;j++)
			{
				if(ppl[i][j]>col_tall[j])
					col_tall[j]=ppl[i][j];
				if(ppl[i][j]<row_short[i])
					row_short[i]=ppl[i][j];
			}
		}
		int tallest=0;
		int shortest=99999;
		for(i=0;i<row_size;i++)
			if(tallest<row_short[i])
				tallest = row_short[i];
		for(j=0;j<col_size;j++)
			if(shortest>col_tall[j])
				shortest = col_tall[j];

		vector<int> ans;
		ans.push_back(tallest);
		ans.push_back(shortest);
		return ans;
	}

};
