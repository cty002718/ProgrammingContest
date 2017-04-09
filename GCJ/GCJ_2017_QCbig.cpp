#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

typedef long long ll;

int main()
{
	int T;
	int c = 0;
	cin >> T;
	while(T--)
	{
		ll input,k;
		cin >> input;
		cin >> k;
		
		ll layer = 1;
		ll two = 1;
		while(k >= two)
		{
			layer++;
			two <<= 1;
		}
		layer--;
		two/=2;
		//cout << layer << " " << two << endl;
		ll anum = 1;
		ll bnum = 0;

		ll countlayer = 1;
		
		ll fac;
		while(1)
		{
			if(layer == countlayer)
			{
				ll co = k - two + 1;
				if(co <= anum) fac = input;
				else fac = input-1;
				break;
			}
			countlayer++;
			ll tmpa = 0;
			ll tmpb = 0;
			if(input & 1)
				tmpa += anum*2;
			else
			{
				tmpa += anum;
				tmpb += anum;
			}

			if((input-1) & 1)
				tmpb += bnum*2;
			else
			{
				tmpa += bnum;
				tmpb += bnum;
			}

			anum = tmpa;
			bnum = tmpb;
			input >>= 1;
		}
		
		ll ansa;
		ll ansb;
		if(fac & 1) ansa = ansb = fac/2;
		else 
		{
			ansa = fac/2;
			ansb = fac/2 - 1;
		}
		printf("Case #%d: %lld %lld\n",++c,max(ansa,ansb),min(ansa,ansb));
	}
	//cout << sum << endl;

	return 0;
}
