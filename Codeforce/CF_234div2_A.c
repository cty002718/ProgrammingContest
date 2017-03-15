#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		char input[20];
		int num[13]={0};
		scanf("%s",input);
		int i,j;
		int count=0;
		for(i=12;i>=1;i--)
		{
			if(12%i!=0)
				continue;
			int left[13]={0};
			for(j=0;j<12;j++)
				if(input[j]=='X')
					left[j%i]++;
			
			int suc=0;
			for(j=0;j<i;j++)
				if(left[j]==12/i)
					suc=1;
			
			if(suc)
			{
				count++;
				num[i]=1;
			}
		}

		printf("%d",count);
		for(i=12;i>=1;i--)
			if(num[i])
				printf(" %dx%d",12/i,i);
		puts("");
	}
}
