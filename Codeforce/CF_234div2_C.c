#include<stdio.h>

int tmpn,tmpm;

void clockwise(int*,int*);
void counter(int*,int*);
void rotate(int*,int*);

int main()
{
	int n,m;
	int x,y,z,p;
	scanf("%d%d",&n,&m);
	scanf("%d%d%d",&x,&y,&z);
	scanf("%d%d%d",&p);

	x%=4;
	y%=2;
	z%=4;
	int i;
	for(i=0;i<p;i++)
	{
		tmpn=n;
		tmpm=m;
		int tmpx,tmpy;
		scanf("%d%d",&tmpx,&tmpy);
		int j;
		for(j=0;j<x;j++)
			clockwise(&tmpx,&tmpy);
		for(j=0;j<y;j++)
			rotate(&tmpx,&tmpy);
		for(j=0;j<z;j++)
			counter(&tmpx,&tmpy);

		printf("%d %d\n",tmpx,tmpy);
	}

	return 0;
}

void clockwise(int* x,int* y)
{
	
}

void counter(int* x,int* y)
{

}

void rotate(int* x,int* y)
{

}
