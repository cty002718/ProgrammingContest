#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int n;
	int i,j;
	const int movex[4]={1,1,1,2};
	const int movey[4]={0,-1,1,0};
	char map[103][103];
	memset(map,'.',sizeof(map));
	
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		getchar();
		for(j=1;j<=n;j++)
			scanf("%c",&map[i][j]);
	}

	int suc=1;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(map[i][j]=='#')
			{
				int k;
				for(k=0;k<4;k++)
					if(map[i+movex[k]][j+movey[k]]=='#')
						map[i+movex[k]][j+movey[k]]='.';
					else
						suc=0;
			}

	if(suc)
		printf("YES\n");
	else
		printf("NO\n");
	
	return 0;
}


