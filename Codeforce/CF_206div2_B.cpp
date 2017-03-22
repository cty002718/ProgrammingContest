#include<iostream>
#include<cstdio>
using namespace std;

typedef long long ll;

int main()
{
	ll c1,c2,c3,c4;
	cin >> c1 >> c2 >> c3 >> c4;
	
	ll bus[1003];
	ll tro[1003]; 
	ll busbuy[1003];
	ll trobuy[1003];
	int n,m;
	cin >> n >> m;

	int i;
	for(i=0;i<n;i++)
		scanf("%lld",&bus[i]);
	for(i=0;i<m;i++)
		scanf("%lld",&tro[i]);
	
	
	for(i=0;i<n;i++)
	{
		if(bus[i] * c1 < c2)
			busbuy[i] = bus[i] * c1;
		else
			busbuy[i] = c2;
	}

	for(i=0;i<m;i++)
	{
		if(tro[i] * c1 < c2)
			trobuy[i] = tro[i] * c1;
		else
			trobuy[i] = c2;
	}
	
	ll bustotal = 0;
	ll trototal = 0;
	for(i=0;i<n;i++)
		bustotal += busbuy[i];	
	for(i=0;i<m;i++)
		trototal += trobuy[i];
	
	bustotal = min(bustotal,c3);
	trototal = min(trototal,c3);
	
	ll ans = bustotal + trototal;
	ans = min(ans,c4);
	cout << ans << endl; 
	return 0;
}
