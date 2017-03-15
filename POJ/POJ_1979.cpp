#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n,m;
char map[25][25];
int movex[4]={1,-1,0,0};
int movey[4]={0,0,1,-1};

int dfs(int,int);

int main()
{
	while(cin >> m >> n && m!=0)
	{
		memset(map,0,sizeof(map));
		int i,j;
		int sx,sy;
		for(i=1;i<=n;i++)
		{
			getchar();
			for(j=1;j<=m;j++)
			{
				scanf("%c",&map[i][j]);
				if(map[i][j]=='@')
				{
					sx=i;
					sy=j;
				}
			}
		}	

		cout << dfs(sx,sy) << endl;
	}

	return 0;
}

int dfs(int x,int y)
{
	int i;
	int sum=0;
	for(i=0;i<4;i++)
	{
		int newx=x+movex[i];
		int newy=y+movey[i];
		if(map[newx][newy]=='.')
		{
			map[newx][newy]='#';
			sum+=dfs(newx,newy);
		}
	}
	return sum+1;
}
