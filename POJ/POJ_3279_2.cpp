#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

int n,m;
int tmp[20][20];
int map[20][20];
int ans2[20][20];
int nowc=1e9;
void button(int,int);

int main()
{
	int i,j;
	cin >> m >> n;
	
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			cin >> map[i][j];

    int k;
    for(k=0;k<1<<n;k++)
    {
        int c=0;
        int ans[20][20];
        memset(ans,0,sizeof(ans));
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
                tmp[i][j]=map[i][j];
        
        for(j=0;j<n;j++)
        {
            ans[1][n-j]=k>>j&1;
            if(ans[1][n-j])
            {
                c++;
                button(1,n-j);
            }
        }
        
        for(i=2;i<=m;i++)
            for(j=1;j<=n;j++)
                if(tmp[i-1][j]==1)
                {
                    button(i,j);
                    c++;
                    ans[i][j]=1;
                }
        
        int suc=1;
        for(i=1;i<=n;i++)
            if(tmp[m][i]==1)
                suc=0;
        
        if(suc && c<nowc)
        {
            for(i=1;i<=m;i++)
                for(j=1;j<=n;j++)
                    ans2[i][j] = ans[i][j];
            nowc=c;
        }
        
    }
	if(nowc!=1e9)
	{
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
            {
                if(j!=1)
                    cout << " ";
				cout << ans2[i][j];
            }
            cout << endl;
		}
	}
	else
		cout << "IMPOSSIBLE" << endl;
	
	return 0;
}

void button(int i,int j)
{
	tmp[i][j]^=1;
	tmp[i][j+1]^=1;
	tmp[i][j-1]^=1;
	tmp[i+1][j]^=1;
	tmp[i-1][j]^=1;
	return;
}
