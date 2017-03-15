#include<stdio.h>

int main()
{
	int n,t,c;
	scanf("%d%d%d",&n,&t,&c);
	int input[200003];
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&input[i]);
	
	int sum=0;
	int count=0;
	for(i=0;i<n;i++)
	{
		if(input[i]<=t)
			sum++;
		else
			sum=0;

		if(sum>=c)
			count++;
	}

	printf("%d\n",count);

	return 0;
}
