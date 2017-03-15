#include<iostream>
#include<cstring>
using namespace std;

int input[10][10];
int row[10][10];
int col[10][10];
int square[3][3][10];
int suc;
int num;
int d;

void dfs(int,int);

int main()
{
	int c = 0;
	while(cin >> num)
	{
		d = num; 
		num *= num;
		memset(row,0,sizeof(row));
		memset(col,0,sizeof(col));
		memset(square,0,sizeof(square));

		
		int i,j;
		for(i=0;i<num;i++)
			for(j=0;j<num;j++)
			{
				cin >> input[i][j];
				row[i][input[i][j]]++;
				col[j][input[i][j]]++;
				square[i/d][j/d][input[i][j]]++;
			}
		
		if(c!=0)
			cout << endl;
		c = 1;

		suc = 0;
		dfs(0,0);
		if(!suc)	
			cout << "NO SOLUTION" << endl;
	}
	return 0;
}

void dfs(int n,int m)
{
	if(m==num && n==num-1)
	{
		int i,j;
		suc = 1;
		for(i=0;i<num;i++)
			{
				for(j=0;j<num;j++)
				{
					if(j!=0)
						cout << " ";
					cout << input[i][j];
				}
				cout << endl;
			}
		
		return;
	}
	if(m==num)
	{
		dfs(n+1,0);
		return;
	}
	if(input[n][m]!=0)
	{
		dfs(n,m+1);
		return;
	}

	int i;
	for(i=1;i<=num;i++)
	{
		if(row[n][i]==0 &&
		   col[m][i]==0 &&
		   square[n/d][m/d][i]==0)
		  {
		  	input[n][m] = i;
			row[n][i] = 1;
			col[m][i] = 1;
			square[n/d][m/d][i] = 1;
			dfs(n,m+1);
			if(suc)
				return;
			input[n][m] = 0;
			row[n][i] = 0;
			col[m][i] = 0;
			square[n/d][m/d][i] = 0;
		}
	}
}
