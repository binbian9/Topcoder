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

#define pb push_back

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()
#define gcd(a,b) __gcd(a,b)
#define EQ(a,b) (abs(a-b) <eps)
#define sqr(a) ((a)*(a))
#define popcount(n) __builtin_popcount(n)


class AccountBalance {

	int test(string s)
	{
		string temp=s;
		string::size_type pos1,pos2;
		vector<string> v;
		pos1 = 0;
		pos2 = s.find(' ');
		while(string::npos !=pos2)
		{

			v.push_back(temp.substr(pos1,pos2-pos1));
			pos1=pos2+1;
			pos2=s.find(' ',pos1);

		}
		v.push_back(s.substr(pos1));
		//cout<<v[1]<<endl;
		stringstream ss;
		ss<<v[1];
		int ans ;
		ss>>ans;
		if(v[0]=="C")
			return ans;
		else
			return -ans;
	}
	public: int processTransactions(int startingBalance, vector<string> transactions) {
		int sum = startingBalance;
		int size = transactions.size();
		for(int i=0;i<size;i++)
		{
			sum+=test(transactions[i]);
		}
		return sum;
	}

};
