#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	int i,j;
	int input[1003];
	for(i=1;i<=n;i++)
		cin >> input[i];
	
	int dp[1003][33];
	memset(dp,0,sizeof(dp));
	
	for(i=1;i<=n;i++)
		if(input[i]==1)
			dp[i][0]=dp[i-1][0]+1;
		else
			dp[i][0]=dp[i-1][0];
	
	for(i=1;i<=n;i++)
		for(j=1;j<=i && j<=m;j++)
		{
			int suc=0;
			if(j%2==0 && input[i]==1)
				suc=1;
			if(j%2==1 && input[i]==2)
				suc=1;
			
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+suc;
		}

	cout << dp[n][m] << endl;
	
	return 0;
}
