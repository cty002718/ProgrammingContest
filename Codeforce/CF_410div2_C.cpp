#include<iostream>
using namespace std;

typedef long long ll;

ll input[100003];

ll gcd(ll a, ll b)
{
	if(b == 0) return a;
	return gcd(b,a%b);
}

int main()
{
	int n;
	cin >> n;
	int i;
	for(i=0;i<n;i++)
		scanf("%lld",&input[i]);
	
	ll g = gcd(input[0], input[1]);
	for(i=2;i<n;i++)
		g = gcd(g,input[i]);

	ll num = 0;
	for(i=0;i<n-1;i++)
	{
		while(input[i] & 1)
		{
			num++;
			ll tmp = input[i];
			input[i] = input[i] - input[i+1];
			input[i+1] = tmp + input[i+1];
		}

	}

	while(input[n-1] & 1)
	{
		num++;
		ll tmp = input[n-2];
		input[n-2] = input[n-2] - input[n-1];
		input[n-1] = tmp + input[n-1];
	}
	
	cout << "YES" << endl;
	if(g == 1) printf("%lld\n",num);
	else printf("0\n");
	return 0;
}
