#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;

struct node
{
	int x,y;
	int dis;
};

bool visit[1003][1003];
char map[1003][1003];
const int movex[4]={0,0,1,-1};
const int movey[4]={1,-1,0,0};

int main()
{
	int H,W,N;
	int i,j;
	for(i=0;i<1003;i++)
		for(j=0;j<1003;j++)
			map[i][j]='X';
	int sx,sy;
	cin >> H >> W >> N;
	
	for(i=1;i<=H;i++)
	{
		getchar();
		for(j=1;j<=W;j++)
		{
			scanf("%c",&map[i][j]);
			if(map[i][j]=='S')
			{
				sx=i;
				sy=j;
			}
		}
	}

	int k;
	int ans=0;
	for(k=1;k<=N;k++)
	{
		memset(visit,false,sizeof(visit));
		queue<node> q;
		node tmp;tmp.x=sx;tmp.y=sy;tmp.dis=0;
		visit[sx][sy]=true;
		q.push(tmp);
		while(!q.empty())
		{
			node a;
			a=q.front();q.pop();
			if(map[a.x][a.y]==k+'0')
			{
				sx=a.x;
				sy=a.y;
				ans+=a.dis;
				break;
			}
			int i;
			for(i=0;i<4;i++)
			{
				int newx=a.x+movex[i];
				int newy=a.y+movey[i];
				if(!visit[newx][newy] && map[newx][newy]!='X')
				{
					visit[newx][newy]=true;
					node b;
					b.x=newx;b.y=newy;b.dis=a.dis+1;
					q.push(b);
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}
