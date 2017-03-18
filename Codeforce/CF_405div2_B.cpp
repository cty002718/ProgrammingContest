#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;

typedef long long ll;

int p[150003];
ll line[150003];
ll num[150003];

int find(int x)
{
	if(p[x] == x)
		return x;
	return p[x] = find(p[x]);
}

void uni(int x, int y)
{
	int fx = find(x);
	int fy = find(y);

	if(fx!=fy)
	{
		p[fy] = fx;
		num[fx] += num[fy];
		line[fx] += line[fy];
		num[fy] = 0;
		line[fy] = 0;
	}
	line[fx]++;
}

int main()
{
	int n, m;
	int i;
	cin >> n >> m;
	for(i=1;i<=n;i++)
	{
		p[i] = i;
		num[i] = 1;
	}

	for(i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		uni(a,b);
	}

	int suc = 1;
	for(i=1;i<=n;i++)
	{
		ll tmp = num[i];
		if((tmp*(tmp-1))/2 != line[i])
			suc = 0;
	}

	if(suc) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
