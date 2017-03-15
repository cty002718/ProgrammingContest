#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

int n,m;
int tmp[20][20];
int map[20][20];
int ans2[20][20];
int solution[20];
int nowc=1e9;
void dfs(int);
void button(int,int);

int main()
{
	int i,j;
	cin >> m >> n;
	
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			cin >> map[i][j];

	dfs(1);	
	if(nowc!=1e9)
	{
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
            {
                if(j!=1)
                    cout << " ";
				cout << ans2[i][j];
            }
            cout << endl;
		}
	}
	else
		cout << "IMPOSSIBLE" << endl;
	
	return 0;
}

void dfs(int a)
{
	if(a==n+1)
	{
		int c=0;
		int ans[20][20];
		memset(ans,0,sizeof(ans));
		int i,j;
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
				tmp[i][j]=map[i][j];

		for(i=1;i<=n;i++)
			if(solution[i])
			{
				button(1,i);
				ans[1][i]=1;
				c++;
			}

		for(i=2;i<=m;i++)
			for(j=1;j<=n;j++)
				if(tmp[i-1][j]==1)
				{
					button(i,j);
					c++;
					ans[i][j]=1;
				}
		
		int suc=1;
		for(i=1;i<=n;i++)
			if(tmp[m][i]==1)
				suc=0;

		if(suc && c<nowc)
		{
			for(i=1;i<=m;i++)
				for(j=1;j<=n;j++)
					ans2[i][j] = ans[i][j];
				nowc=c;
		}
			
		return;
	}
	
	solution[a]=0;
	dfs(a+1);
	solution[a]=1;
	dfs(a+1);
	return;

}

void button(int i,int j)
{
	tmp[i][j]^=1;
	tmp[i][j+1]^=1;
	tmp[i][j-1]^=1;
	tmp[i+1][j]^=1;
	tmp[i-1][j]^=1;
	return;
}
