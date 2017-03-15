#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int map[303][303];

int main()
{
	int n,m;
	cin >> n >> m;
	int i,j,k;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i!=j)
				map[i][j]=1e9;

	for(i=0;i<m;i++)
	{
		int tmp;
		int input[303];
		scanf("%d",&tmp);
		for(j=0;j<tmp;j++)
			scanf("%d",&input[j]);

		for(j=0;j<tmp;j++)
			for(k=j+1;k<tmp;k++)
				map[input[j]][input[k]]=map[input[k]][input[j]]=1;
	}
	
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(map[i][k]+map[k][j]<map[i][j])
					map[i][j]=map[i][k]+map[k][j];

	int ans=1e9;
	for(i=1;i<=n;i++)
	{
		int sum=0;
		for(j=1;j<=n;j++)
			sum+=map[i][j];
		ans=min(ans,sum);
	}
	
//	cout << ans << endl;
	cout << (int)((double)ans/(n-1)*100) << endl;
	return 0;
}
