#include<iostream>
using namespace std;

typedef long long ll;

int map[20][20];
ll dp[1<<18][20];

int main()
{
	int n,m,k;
	cin >> n >> m >> k;
	int i,j;
	int weight[20];
	for(i=1;i<=n;i++)
		cin >> weight[i];
	
	for(i=0;i<k;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		map[a][b] = c;
	}
	
	ll ans = 0;
	for(i=1;i<(1<<n);i++)
		for(j=1;j<=n;j++)
		{
			int tmp = 1<<(j-1);
			if((tmp & i) == 0) continue;
			tmp = ~tmp;
			tmp = tmp & i;
			int k;
			for(k=0;k<n;k++)
			{
				int tmp2 = 1<<k;
				if((tmp2 & i) == 0) continue;
				dp[i][j] = max(dp[i][j],dp[tmp][k+1] + map[k+1][j]+weight[j]);
			}

			int count = 0;
			int tmpi = i;
			while(tmpi)
			{
				if((tmpi & 1) == 1) count++;
				tmpi >>= 1;
			}

			if(count == m) ans = max(ans,dp[i][j]);
		}
	
	printf("%lld\n",ans);
	return 0;
}
