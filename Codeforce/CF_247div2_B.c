#include<stdio.h>

void en(int);

int sum[6][6];
int solution[6];
int used[6]={0};
int max=0;

int main()
{
	int i,j;
	for(i=1;i<=5;i++)
		for(j=1;j<=5;j++)
			scanf("%d",&sum[i][j]);

	en(0);
	printf("%d\n",max);
	return 0;
}

void en(int n)
{
	if(n==5)
	{
		int sum1=0;
		sum1=sum[solution[0]][solution[1]]+
			 sum[solution[1]][solution[0]]+
			 sum[solution[2]][solution[3]]*2+
			 sum[solution[3]][solution[2]]*2+
			 sum[solution[1]][solution[2]]+
			 sum[solution[2]][solution[1]]+
			 sum[solution[3]][solution[4]]*2+
			 sum[solution[4]][solution[3]]*2;

		if(sum1>max)
			max=sum1;
		
		return;
	}

	int i;
	for(i=1;i<=5;i++)
		if(used[i]==0)
		{
			used[i]=1;
			solution[n]=i;
			en(n+1);
			used[i]=0;
		}
}
