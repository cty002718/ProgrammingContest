#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int p[2000003];
int num[2000003];
const int movex[4] = {0,0,1,-1};
const int movey[4] = {1,-1,0,0};

int find(int n)
{
	if(p[n] == n) return n;
	return p[n] = find(p[n]);
}

void uni(int x, int y)
{
	int fx = find(x);
	int fy = find(y);

	if(fx!=fy)
	{
		num[fx] += num[fy];
		num[fy] = 0;
		p[fy] = fx;
	}
}

char map[1003][1003];

int main()
{
	int n,m;
	cin >> n >> m;
	memset(map,'*',sizeof(map));
	int i,j;
	for(i=0;i<2000003;i++)
	{
		p[i] = i;
		num[i] = 1;
	}
	for(i=1;i<=n;i++)
	{
		getchar();
		for(j=1;j<=m;j++)
			scanf("%c",&map[i][j]);
	}

	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(map[i][j] == '.')
			{
				int k;
				for(k=0;k<4;k++)
				{
					int newx = i + movex[k];
					int newy = j + movey[k];
					if(map[newx][newy] == '.')
						uni(i*m+j,newx*m+newy);
				}
			}
		}

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(map[i][j] == '*')
			{
				int k;
				vector<int> v;
				for(k=0;k<4;k++)
				{
					int newx = i + movex[k];
					int newy = j + movey[k];
					if(map[newx][newy] == '*') continue;
					int newput = newx*m+newy;
					int suc = 1;
					int l;
					for(l=0;l<v.size();l++)
						if(find(newput) == find(v[l]))
							suc = 0;
					
					if(suc == 1) v.push_back(newput);
				}

				int sum = 1;
				for(k=0;k<v.size();k++)	
					sum += num[find(v[k])];
				
				//cout << endl;
				printf("%d",sum%10);
			}
			else printf("%c",'.');
		}
		puts("");
	}
	return 0;
}
