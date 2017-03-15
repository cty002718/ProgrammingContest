#include<iostream>
using namespace std;

int main()
{
	int n;
	while(cin >> n)
	{
		int i,j;
		int map[503][503];
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				cin >> map[i][j];
		
		int d[503];
		bool visit[503];
		for(i=0;i<n;i++)
		{
			d[i]=0xfffffff;
			visit[i]=false;
		}
		d[0]=0;
		visit[0]=true;
		
		int inside=0;
		int sum=0;
		for(i=0;i<n-1;i++)
		{
			int small=0xfffffff;
			for(j=0;j<n;j++)
				if(!visit[j] && map[inside][j]<d[j])
					d[j]=map[inside][j];
			
            for(j=0;j<n;j++)
				if(d[j]<small && !visit[j])
				{
					small=d[j];
					inside=j;
				}
			
            //cout << inside;
            //cout << " " << d[inside] << endl;
            
			visit[inside]=true;
			sum+=small;
		}
	
		cout << sum << endl;
	}
	return 0;
}
