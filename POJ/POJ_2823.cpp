#include<iostream>
#include<cstdio>
using namespace std;

int input[1000003];
int deque[1000003];

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&input[i]);
	
	int left = 0;
	int right = 0;
	
	for(i=0;i<n;i++)
	{
		while(left!=right && input[deque[right-1]] >= input[i])
			right--;

		deque[right++] = i;
		
		if(i-k+1>=0)
		{
			if(i-k+1!=0)
				printf(" ");
			printf("%d",input[deque[left]]);
		}

		if(deque[left]==i-k+1)
			left++;
	}
    puts("");
	left = 0;
	right = 0;
	for(i=0;i<n;i++)
	{
		while(left!=right && input[deque[right-1]] <= input[i])
			right--;

		deque[right++] = i;
		
		if(i-k+1>=0)
		{
			if(i-k+1!=0)
				printf(" ");
			printf("%d",input[deque[left]]);
		}

		if(deque[left]==i-k+1)
			left++;
	}
    puts("");
	
	return 0;
}
