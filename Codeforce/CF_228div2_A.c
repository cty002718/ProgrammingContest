#include<stdio.h>

int main()
{
	int n;
	int i,j;
	int input[103];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&input[i]);
	
	for(i=100;i>=1;i--)
	{
		int suc=1;
		for(j=0;j<n;j++)
			if(input[j]%i!=0)
				suc=0;	
		if(suc)
			break;
	}

	printf("%d\n",i*n);
	return 0;
}				
