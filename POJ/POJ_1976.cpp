#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int num;
	cin >> num;
	while(num--)
	{
		int n;
		int input[50003];
		int tran[50003]={0};
		long long dp[4][50003];
		memset(dp,0,sizeof(dp));
		cin >> n;
		int i;
		for(i=0;i<n;i++)
			scanf("%d",&input[i]);
		int dis;
		cin >> dis;
		
		for(i=0;i<dis;i++)
			tran[0]+=input[i];
		for(i=1;i<n-dis+1;i++)
			tran[i]=tran[i-1]-input[i-1]+input[i+dis-1];
		
		for(i=0;i<n-dis+1;i++)
			dp[1][i]=tran[i];

		long long big=dp[1][0];
		for(i=dis;i<n-dis+1;i++)
		{
			dp[2][i]=tran[i]+big;
			big=max(big,dp[1][i-dis+1]);
		}

		big=dp[2][dis];
		for(i=dis*2;i<n-dis+1;i++)
		{
			dp[3][i]=tran[i]+big;
			big=max(big,dp[2][i-dis+1]);
		}

        big=dp[3][dis*2];
        for(i=dis*2+1;i<n-dis+1;i++)
            big=max(big,dp[3][i]);
        
        cout << big << endl;
	}
}
