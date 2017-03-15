#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int n,m;
	int c=0;
	while(cin >> n >> m && n!=0)
	{
		int num[55]={};
		int i,j;
		for(i=0;i<n;i++)
		{
			int tmp;
			cin >> tmp;
			num[tmp]++;
		}
		long long dp[55][55];
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=n;j++)
				dp[i][j]=dp[i-1][j];
			for(j=0;j<=n;j++)
				for(int k=1;k<=num[i] && j-k>=0;k++)
					dp[i][j]+=dp[i-1][j-k];
		}

		cout << "Case " << ++c << ":" << endl;
		while(m--)
		{
			int tmp;
			cin >> tmp;
			cout << dp[n][tmp] << endl;
		}
	}

	return 0;
}
