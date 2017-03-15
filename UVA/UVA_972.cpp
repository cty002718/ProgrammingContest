#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main()
{
	int n,m;
	int c=0;
	while(cin >> n)
	{
		pair<double,double> f[303];
		pair<double,double> g[303];
		int i;
		double ac = 0;
		for(i=0;i<n;i++)
		{
			double a,b;
			cin >> a >> b;
			f[i].first = ac;
			f[i].second = a;
			ac += b;
        }
		
		ac = 0;
		cin >> m;
		for(i=0;i<m;i++)
		{
			double a,b;
			cin >> a >> b;
			g[i].first = ac;
			g[i].second = a;
			ac += b;
		}

		f[n].first = 1e9;
		g[m].first = 1e9;
		double nowf = f[0].second;
		double nowg = g[0].second;
		double ans = max(nowf,nowg);
		int j;
		for(i=1,j=1;i<n || j<m;)
		{
            if(abs(g[j].first - f[i].first) < 1e-10)
			{
				nowg = g[j].second;
                nowf = f[i].second;
				ans = min(ans,max(nowf,nowg));
				j++;
                i++;
			}
            else if(g[j].first > f[i].first)
			{
				nowf = f[i].second;
				ans = min(ans,max(nowf,nowg));
				i++;
			}
            else
            {
                nowg = g[j].second;
                ans = min(ans,max(nowf,nowg));
                j++;
            }
		}
        
        printf("%.3lf\n",ans);
	}

	return 0;
}
