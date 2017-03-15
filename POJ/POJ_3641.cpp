#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	long long p,a;
	while(cin >> p >> a && p!=0)
	{
		long long tmp=p;
		long long i;
		int suc=1;
		for(i=2;i*i<=p;i++)
			if(p%i==0)
				suc=0;
		if(suc)
		{
			cout << "no" << endl;
			continue;
		}
		long long ans=1;
		long long base=a;
		while(tmp)
		{
			if(tmp&1)
				ans=base*ans%p;
			base=base*base%p;
			tmp>>=1;
		}

		if(ans==a)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}

	return 0;
}
