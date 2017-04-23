#include<iostream>
using namespace std;

typedef long long ll;

int n;
ll dat[1000003];

void init(int);
void update(int, ll);
ll query(int,int,int,int,int);

int main()
{
	int n_;
	int c = 0;
	while(cin >> n_ && n_!=0)
	{
		if(c != 0) puts("");
		printf("Case %d:\n",++c);
		init(n_);
		int i;
		for(i=1;i<=n_;i++)
			scanf("%lld",&dat[i+n-1]);

		for(i=n-1;i>=1;i--)
			dat[i] = dat[i*2] + dat[i*2+1];
		
		while(1)
		{
			char input[5];
			scanf("%s",input);

			if(input[0] == 'E')
				break;
			if(input[0] == 'M')
			{
				int a,b;
				scanf("%d%d",&a,&b);
				printf("%lld\n",query(a,b,1,1,n));
			}
			else
			{
				int a;
				ll b;
				scanf("%d%lld",&a,&b);
				update(a,b);
			}
		}
	}

	return 0;
}

void init(int n_)
{
	n = 1;
	while(n < n_)
		n <<= 1;

	int i;
	for(i=1;i<2*n;i++)
		dat[i] = 0;
}

void update(int a, ll b)
{
	a = a + n - 1;
	dat[a] = b;
	while(a > 1)
	{
		a/=2;
		dat[a] = dat[a*2] + dat[a*2+1];
	}
}

ll query(int a, int b, int k, int l, int r)
{
	if(a > r || b < l) return 0;
	else if(a<=l && b>=r) return dat[k];
	else return query(a,b,k*2,l,(l+r)/2) +
			    query(a,b,k*2+1,(l+r)/2+1,r);
}
