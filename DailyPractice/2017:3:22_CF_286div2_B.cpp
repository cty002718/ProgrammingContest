#include<iostream>
#include<vector>
using namespace std;

int p[103][103];

int find(int x, int c)
{
	if(p[c][x] == x) return x;
	return p[c][x] = find(p[c][x],c);
}

void uni(int x,int y,int c)
{
	int fx = find(x,c);
	int fy = find(y,c);

	if(fx!=fy) p[c][fx] = fy;
}

int main()
{
	int n,m;
	cin >> n >> m;
	int i;
	int j;
	for(i=0;i<103;i++)
		for(j=0;j<103;j++)
			p[i][j] = j;

	for(i=0;i<m;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		uni(a,b,c);
	}

	int q;
	cin >> q;
	for(i=0;i<q;i++)
	{
		int a,b;
		cin >> a >> b;

		int ans = 0;
		for(j=1;j<=m;j++)
			if(find(a,j) == find(b,j))
				ans++;
		cout << ans << endl;
	}

	return 0;
}

