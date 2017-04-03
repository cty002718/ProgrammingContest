#include<iostream>
using namespace std;

typedef long long ll;
ll MOD = 1e8;

ll dp[103][103][13][2];

int main()
{
	int a,b,sa,sb;
	cin >> a >> b >> sa >> sb;
	
	int i,j,k,l;
	
	dp[1][0][1][0] = dp[0][1][1][1] = 1;
	for(i=1;i<=sa;i++)
		dp[i][0][i][0] = 1;
	for(i=1;i<=sb;i++)
		dp[0][i][i][1] = 1;
	
	for(i=1;i<=a;i++)
		for(j=1;j<=b;j++)
		{
			for(k=1;k<=min(sa,i);k++)
			{
				if(k == 1)
				{
					ll sum = 0;
					for(l=0;l<=min(sb,j);l++)
						sum = (sum + dp[i-1][j][l][1]) % MOD;
					dp[i][j][k][0] = sum;
				}
				else
					dp[i][j][k][0] = dp[i-1][j][k-1][0];
			}

			for(k=1;k<=min(sb,j);k++)
			{
				if(k == 1)
				{
					ll sum = 0;
					for(l=0;l<=min(sa,i);l++)
						sum = (sum + dp[i][j-1][l][0]) % MOD;
					dp[i][j][k][1] = sum;
				}
				else
					dp[i][j][k][1] = dp[i][j-1][k-1][1];
			}
		}

	ll ans = 0;
	for(i=0;i<=sa;i++)
		ans = (ans + dp[a][b][i][0]) % MOD;
	for(i=0;i<=sb;i++)
		ans = (ans + dp[a][b][i][1]) % MOD;
	
	cout << ans << endl;
	return 0;
}
