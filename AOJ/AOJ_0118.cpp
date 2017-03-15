#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int n,m;
char map[103][103];
const int movex[4]={0,0,1,-1};
const int movey[4]={1,-1,0,0};

void dfs(int,int,char);

int main()
{
	while(cin >> n >> m && n!=0)
	{
		int c=0;
		int i,j;
		for(i=0;i<n;i++)
		{
			getchar();
			for(j=0;j<m;j++)
				scanf("%c",&map[i][j]);
		}

		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(map[i][j]!='h')
				{
					c++;
					dfs(i,j,map[i][j]);
				}
		

		cout << c << endl;
	}

	return 0;
}

void dfs(int x,int y,char tmp)
{
	map[x][y]='h';
	int i;
	for(i=0;i<4;i++)
	{
		int newx=x+movex[i];
		int newy=y+movey[i];
		
		if(newx>=0 && newx<n && newy>=0 && newy<m && map[newx][newy]==tmp)
			dfs(newx,newy,tmp);
	}
	
}
