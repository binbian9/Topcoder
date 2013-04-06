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


class FarFromPrimes {

	public: int count(int A, int B) {
		int j;
		int prime[100012];
		FOR(i,0,100012)
			prime[i]=1;
		FOR(i,2,B+1)
			if(prime[i])
				for(j=i+i;j<B+1;j=j+i)
					prime[j]=0;
		int counter=0;
		FOR(i,A,B+1)
			if(i-10>0 && i+10<=100011)
			{
				bool check = true;
				for(j=i-10;j<i+11;j++)
				{
					if(prime[j])
						check = false;
				}
				if(check)
					counter++;
			}
		return counter;
	}

};
