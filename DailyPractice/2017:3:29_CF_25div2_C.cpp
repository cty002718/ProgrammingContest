#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

typedef long long ll;

ll dp[303][303];

int main()
{
	int n;
	cin >> n;
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&dp[i][j]);
	
	int m;
	int d = 0;
	cin >> m;
	while(m--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
        
        if(dp[a][b] > c)
            dp[a][b] = dp[b][a] = c;
        for(i=1;i<=n;i++)
            dp[a][i] = dp[i][a] = min(dp[i][a],dp[a][b]+dp[b][i]);
        for(i=1;i<=n;i++)
            dp[b][i] = dp[i][b] = min(dp[i][b],dp[a][b]+dp[a][i]);
        
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				dp[i][j] = min(dp[i][j],dp[i][a]+dp[a][j]);
				dp[i][j] = min(dp[i][j],dp[i][b]+dp[b][j]);
                dp[j][i] = dp[i][j];
            }

		ll sum = 0;
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				sum += dp[i][j];
		if(d!=0) printf(" ");
		printf("%lld",sum);
		d = 1;
	}
	cout << endl;

	return 0;
}
