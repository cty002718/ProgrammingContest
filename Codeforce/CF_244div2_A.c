#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int count=0;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		if(tmp==-1)
		{
			if(sum!=0)
				sum--;
			else
				count++;
		}

		else
			sum+=tmp;
	}

	printf("%d\n",count);
	
	return 0;
}
