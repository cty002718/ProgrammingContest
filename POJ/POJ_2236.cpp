#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

struct point
{
	int x,y;
}p[1005];

bool map[1005][1005];
bool fix[1005];
int f[1005];

void uni(int,int);
int fa(int);

int main()
{
	int n;
	int i,j;
	double d;
	cin >> n >> d;
	
	for(i=1;i<=n;i++)
		scanf("%d%d",&p[i].x,&p[i].y);
		
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
		{
			double tmpx=p[i].x-p[j].x;
			double tmpy=p[i].y-p[j].y;
			double tmp=sqrt(tmpx*tmpx+tmpy*tmpy);
			if(tmp<=d)
				map[i][j]=map[j][i]=true;
		}
	
	for(i=1;i<=n;i++)
		f[i]=i;
	
	char tmp[5];
	while(scanf("%s",tmp)!=EOF)
	{
		if(tmp[0]=='O')
		{
			int a;
			scanf("%d",&a);
			fix[a]=true;
			for(i=1;i<=n;i++)
				if(map[a][i] && fix[i])
					uni(a,i);
		}

		else
		{
			int a,b;
			scanf("%d%d",&a,&b);
			if(fa(a)==fa(b))
				printf("SUCCESS\n");
			else
				printf("FAIL\n");
		}

	}

	return 0;
}

void uni(int a,int b)
{
	if(fa(a)==fa(b))
		return;
	int fx=f[a];
	int fy=f[b];
	f[fy]=fx;
	return;
}

int fa(int a)
{
	if(a==f[a])
		return a;
	return f[a]=fa(f[a]);
}


