#include<iostream>
#include<cstring>
using namespace std;

int c[300][300];
int w[300][300];
int root[300][300];

int main()
{
	int n;
	while(cin >> n)
	{
		memset(c,0,sizeof(c));
		memset(w,0,sizeof(w));
		memset(root,0,sizeof(root));
		int i;
		int input[300];
		for(i=1;i<=n;i++)
			cin >> input[i];
		
		for(i=1;i<=n;i++)
		{
			w[i][i] = input[i];
			c[i][i] = 0;
			root[i][i] = i;
		}
		int k,j;
		for(k=1;k<=n;k++)
			for(i=1;i+k<=n;i++)
			{
				int j = i + k;
				c[i][j] = 1e9;
				w[i][j] = w[i][j-1] + input[j];

				int r;
				for(r=root[i][j-1];r<=root[i+1][j];r++)
				{
					int tmp = c[i][r-1] + c[r+1][j] + w[i][j] - input[r];
					if(tmp < c[i][j])
					{
						c[i][j] = tmp;
						root[i][j] = r; 
					}
				}
			}

		cout << c[1][n] << endl;
	}
	return 0;
}
