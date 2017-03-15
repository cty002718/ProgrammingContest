#include<iostream>
#include<cstdio>
using namespace std;

int n,m;
char map[103][103];
const int movex[8]={1,1,1,-1,-1,-1,0,0};
const int movey[8]={1,0,-1,1,0,-1,1,-1};

void dfs(int,int);

int main()
{
	cin >> n >> m;
	int i,j;
	for(i=0;i<n;i++)
	{
		getchar();
		for(j=0;j<m;j++)
			scanf("%c",&map[i][j]);
	}

	int c=0;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(map[i][j]=='W')
			{
				dfs(i,j);
				c++;
			}
    
    cout << c << endl;

	return 0;
}

void dfs(int x,int y)
{
	map[x][y]='.';
	int i;
	for(i=0;i<8;i++)
	{
		int newx=x+movex[i];
		int newy=y+movey[i];

		if(newx>=0 && newx<n && newy>=0 && newy<m && map[newx][newy]=='W')
			dfs(newx,newy);
	}
}
