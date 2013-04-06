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

class CakeParty {

	public: string makeMove(vector<int> pieces) {
		int i;
		int size = pieces.size();
		stringstream ss;
		if(size==1)
		{
			ss<<"CAKE 0 PIECES "<<pieces[0];
		}
		else if(size==2)
		{
			if(pieces[0]==pieces[1])
			{
				ss<<"CAKE 0 PIECES 1";
			}
			else if(pieces[0]>pieces[1])
			{
				ss<<"CAKE 0 PIECES "<<pieces[0]-pieces[1];
			}
			else
			{
				ss<<"CAKE 1 PIECES "<<pieces[1]-pieces[0];
			}
		}
		else
		{
			int AND = pieces[0];
			int max = 0;
			int sum=0;
			for(i=0;i<size;i++)
			{
				if(pieces[i]>max)
					max = pieces[i];
				AND=AND&pieces[i];
				sum+=pieces[i];
			}
			if(AND==pieces[0] && sum/size==pieces[0])
			{
				ss<<"CAKE 0 PIECES 1";
			}
			else
			{
				int counter=0;
				int index = 0;
				for(i=size-1;i>=0;i--)
					if(max==pieces[i])
					{
						counter++;
						index = i;
					}
				if(counter!=1)
				{
					vector<string> ans;
					for(i=size-1;i>=0;i--)
						if(pieces[i]==max)
						{
							stringstream kk;
							kk<<"CAKE "<<i<<" PIECES 1";
							ans.push_back(kk.str());
						}
					sort(ans.begin(),ans.end());
					ss<<ans[0];
				}
				else
				{
					int tempk=0;
					for(i=size-1;i>=0;i--)
						if(pieces[i]!=max)
						{
							tempk = pieces[i];
							break;
						}

					stringstream kk;
					stringstream qq;
					kk<<"CAKE "<<index<<" PIECES "<<pieces[index];
					vector<string> ans;
					qq<<"CAKE "<<index<<" PIECES "<<max-tempk+1;
					ans.push_back(kk.str());
					ans.push_back(qq.str());
					sort(ans.begin(),ans.end());
					ss<<ans[0];
				}


			}
		}
		//cout<<__gcd(9,4)<<endl;
		return ss.str();
	}

};
