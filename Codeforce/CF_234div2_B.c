#include<stdio.h>

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int i,j;
	int num[1003]={0};
	int suc=1;
	for(i=0;i<n;i++)
	{
		getchar();
		int g,s;
		for(j=0;j<m;j++)
		{
			char map;
			scanf("%c",&map);
			if(map=='G')
				g=j;
			if(map=='S')
				s=j;
		}
		
		if(s-g>0)
			num[s-g]=1;
		else
			suc=0;
		
		
	}

	int count=0;
	for(i=1;i<=1000;i++)
		if(num[i])
			count++;
	
	if(suc)
		printf("%d\n",count);
	else
		printf("-1\n");

	return 0;
}
