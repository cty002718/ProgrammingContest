#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;

const int movex[4]={0,0,1,-1};
const int movey[4]={1,-1,0,0};

struct node
{
	int x,y;
	node(int x,int y): x(x),y(y){}
};

int main()
{
	char map[503][503];
	memset(map,'X',sizeof(map));
	int n,m;
	cin >> n >> m;
	int i,j;
	for(i=1;i<=n;i++)
	{
		getchar();
		for(j=1;j<=m;j++)
			scanf("%c",&map[i][j]);
	}

	int sx,sy,ex,ey;
	cin >> sx >> sy >> ex >> ey;
	
	queue<node> q;	
	node start(sx,sy);
	q.push(start);
	while(!q.empty())
	{
		node a = q.front(); q.pop();
		int x = a.x;
		int y = a.y;
		int i;
		for(i=0;i<4;i++)
		{
			int newx = x + movex[i];
			int newy = y + movey[i];
			
			if(newx == ex && newy == ey && map[newx][newy] == 'X')
			{
				cout << "YES" << endl;
				exit(0);
			}
			if(map[newx][newy] == '.')
			{
				map[newx][newy] = 'X';
				node b(newx,newy);
				q.push(b);
			}
		}
	}

	cout << "NO" << endl;
	return 0;
}
