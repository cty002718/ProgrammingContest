#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n;
int lazy[20002];

void init();
void update(int,int,int,int,int,int);
void pushdown(int);

int main()
{	
	n = 1;
	int n_ = 8000;
	while(n < n_)
		n <<= 1;
//	cout << n << endl;	
	int m;
	while(cin >> m)
	{
		init();
		while(m--)
		{
			//cout << 123;
			int x1,x2,c;
			scanf("%d%d%d",&x1,&x2,&c);
			update(x1+1,x2,c,1,1,n);
			//cout << 123;
		}

		int i;
		for(i=1;i<n;i++)
			pushdown(i);
		int pre = lazy[n];
		int color[8003];
		memset(color,0,sizeof(color));
		if(pre!=-1) color[pre]++;
		for(i=n+1;i<2*n;i++)
			if(lazy[i] != pre)
			{
				if(lazy[i]!=-1) color[lazy[i]]++;
				pre = lazy[i];
			}
		
		for(i=0;i<=8000;i++)
			if(color[i]!=0)
				cout << i << " " << color[i] << endl;
		cout << endl;
	}

	return 0;
}

void init()
{
	int i;
	for(i=1;i<2*n;i++)
		lazy[i] = -1;
}

void update(int a, int b, int c, int k, int l, int r)
{
	if(a > r || b < l) return;
	else if(a <= l && r <= b) lazy[k] = c;
	else
	{
		//cout << 123;
		pushdown(k);
		update(a,b,c,k<<1,l,(l+r)/2);
		update(a,b,c,k<<1|1,(l+r)/2+1,r);
	}
}

void pushdown(int k)
{
	if(lazy[k]!=-1)
	{
		lazy[k<<1] = lazy[k<<1|1] = lazy[k];
		lazy[k] = -1;
	}
}


