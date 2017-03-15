#include<iostream>
using namespace std;

int main()
{
	int m;
	while(cin >> m && m!=0)
	{
		int i,j,k;
		int map[12][12];
		for(i=0;i<12;i++)
			for(j=0;j<12;j++)
				if(i==j)
					map[i][j]=0;
				else
					map[i][j]=1e9;

		for(i=0;i<m;i++)
		{
			int a,b,c;
			cin >> a >> b >> c;
			map[a][b]=map[b][a]=c;
		}

		for(k=0;k<12;k++)
			for(i=0;i<12;i++)
				for(j=0;j<12;j++)
					if(map[i][k]+map[k][j]<map[i][j])
						map[i][j]=map[i][k]+map[k][j];

		int ans=1e9;
		int ansx;
		for(i=0;i<12;i++)
		{
			long long sum=0;
			for(j=0;j<12;j++)
				if(map[i][j]!=1e9)
					sum+=map[i][j];
			
			if(sum==0)
				continue;
			else
				if(sum<ans)
				{
					ansx=i;
					ans=sum;
				}
		}

		cout << ansx << " " << ans << endl;
	}

	return 0;
}
