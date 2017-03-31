#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;

typedef long long ll;

struct line
{
	int a,b;
	ll c;
}arc[100003];

vector<int> G[100003];

int dfs(int,int);
ll child_num[100003];
int father[100003];

int main()
{
	int n;
	cin >> n;
	int i;
	for(i=1;i<=n-1;i++)
	{
		scanf("%d%d%lld",&arc[i].a,&arc[i].b,&arc[i].c);
		G[arc[i].a].push_back(arc[i].b);
		G[arc[i].b].push_back(arc[i].a);
	}

	dfs(1,-1);
	
	ll sum = 0;
	for(i=1;i<=n-1;i++)
	{
		int a = arc[i].a;
		int b = arc[i].b;
		if(father[a] == b)
			sum += arc[i].c * (child_num[a] * (n - child_num[a]));
		else
			sum += arc[i].c * (child_num[b] * (n - child_num[b]));
	}
	
//	cout << sum << endl;
	
	int q;
	cin >> q;
	while(q--)
	{
		int which,weight;
		scanf("%d%d",&which,&weight);

		int sub = arc[which].c - weight;
		arc[which].c = weight;
		int a = arc[which].a;
		int b = arc[which].b;
		if(father[a] == b)
			sum -= sub * (child_num[a] * (n - child_num[a]));
		else
			sum -= sub * (child_num[b] * (n - child_num[b]));
		
		printf("%.10lf\n",(double)sum/n/(n-1)*6);
	}
	return 0;
}

int dfs(int n, int f)
{
	father[n] = f;
	int i;
	int num = 1;
	for(i=0;i<G[n].size();i++)
		if(G[n][i] != f)
			num += dfs(G[n][i],n);
	return child_num[n] = num;
}
