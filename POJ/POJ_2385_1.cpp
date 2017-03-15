#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int t,w;
	cin >> t >> w;
	int i,j,k;
	int input[1003];
	for(i=1;i<=t;i++)
		cin >> input[i];
	
	int dp[1003][3][33];
	memset(dp,0,sizeof(dp));
	
	if(input[1]==1)
		for(i=0;i<=w;i++)
			dp[1][1][i]=1;
	else
		for(i=0;i<w;i++)
			dp[1][2][i]=1;

	dp[1][2][w]=-1e9;
	for(i=2;i<=t;i++)
		for(j=1;j<=2;j++)
			for(k=w;k>=0;k--)
			{
				int tmp1,tmp2=-1e9;
				if(input[i]==j)
				{
					tmp1=1+dp[i-1][j][k];
					if(k<w)
						tmp2=1+dp[i-1][3-j][k+1];
				}
				else
				{
					tmp1=dp[i-1][j][k];
					if(k<w)
						tmp2=dp[i-1][3-j][k+1];
				}

				dp[i][j][k]=max(tmp1,tmp2);
			}
/*	
	for(i=1;i<=t;i++)
		cout << dp[i][1][0] << " ";
	cout << endl;
	for(i=1;i<=t;i++)
		cout << dp[i][2][0] << " ";
	cout << endl;
*/	int big=0;
	for(i=0;i<=w;i++)
	{
		int tmp=max(dp[t][1][i],dp[t][2][i]);
		big=max(big,tmp);
	}

	cout << big << endl;
	return 0;
}
