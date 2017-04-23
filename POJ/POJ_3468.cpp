#include<iostream>
#include<cstdio>
using namespace std;

typedef long long ll;

int n;
ll data[300000];
ll datb[300000];

void init(int);
void update(int,int,ll,int,int,int);
ll query(int,int,int,int,int);

int main()
{
	int n_,q;
	cin >> n_ >> q;
	init(n_);
	int i;
	for(i=1;i<=n_;i++)
		scanf("%lld",&datb[i+n-1]);
	
	for(i=n-1;i>=1;i--)
		datb[i] = datb[i*2] + datb[i*2+1];

	while(q--)
	{
		char input[5];
		scanf("%s",input);
		if(input[0] == 'Q')
		{
			int a,b;
			scanf("%d%d",&a,&b);
			printf("%lld\n",query(a,b,1,1,n));
		}
		else
		{
			int a,b;
			ll c;
			scanf("%d%d%lld",&a,&b,&c);
			update(a,b,c,1,1,n);
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
	for(i=1;i<n*2;i++)
		data[i] = datb[i] = 0;
}

void update(int a, int b, ll c, int k, int l, int r)
{
	if(a > r || b < l) return;
	else if(a <= l && b >= r) data[k] += c;
	else
	{
		datb[k] += (min(b,r) - max(a,l) + 1) * c;
		update(a,b,c,k*2,l,(l+r)/2);
		update(a,b,c,k*2+1,(l+r)/2+1,r);
	}
	
}

ll query(int a, int b, int k, int l, int r)
{
	if(a > r || b < l) return 0;
	else if(a <= l && b >= r) return datb[k] + data[k] * (r-l+1);
	else
	{
		ll res = (min(b,r) - max(a,l) + 1) * data[k];
		res += query(a,b,k*2,l,(l+r)/2);
		res += query(a,b,k*2+1,(l+r)/2+1,r);
		return res;
	}
}

