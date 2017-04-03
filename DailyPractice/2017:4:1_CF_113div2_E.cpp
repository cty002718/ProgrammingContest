#include<iostream>
using namespace std;

typedef long long ll;

ll MOD = 1e9 + 7;

int main()
{
	int n;
	cin >> n;
	ll dp[2] = {0,1};

	int i;
	for(i=1;i<=n;i++)
	{
		ll tmp = dp[0];
		dp[0] = ((dp[1] * 3 % MOD) + dp[0] * 2) % MOD;
		dp[1] = tmp;
	}
	
	cout << dp[1] << endl;
	return 0;
}
