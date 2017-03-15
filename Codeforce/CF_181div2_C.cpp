#include<iostream>
#define mod 1000000007 
using namespace std;

long long qpow(long long,long long);
void init();

long long p[1000001];
long long revp[1000001];

int main()
{
	init();
	int a,b,n;
	cin >> a >> b >> n;

	int i;
	long long s=0;
	for(i=0;i<=n;i++)
	{
		long long sum=a*i+b*(n-i);
		int suc=1;
		while(sum)
		{
			if(sum%10!=a && sum%10!=b)
			{
				suc=0;
				break;
			}
			sum/=10;
		}

		//cout << suc << endl;
		if(suc==0)
			continue;
		
		s=(s+((p[n]*revp[i]%mod)*revp[n-i])%mod)%mod;
	}

	cout << s << endl;

	return 0;
}

void init()
{
	p[0]=1;
	revp[0]=1;
	int i;
	for(i=1;i<=1000000;i++)
	{
		p[i]=p[i-1]*i%mod;
		revp[i]=qpow(p[i],mod-2);
	}
	return;
}

long long qpow(long long a,long long b)
{
	long long ans=1;
	while(b)
	{
		if(b%2)
			ans = ans*a%mod;
		a = a*a%mod;
		b/=2;
	}
	return ans;
}

