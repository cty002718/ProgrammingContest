#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstdlib>
using namespace std;

typedef long long ll;

int main()
{
	int T;	
	int co = 0;
	cin >> T;
	while(T--)
	{
		int r,c;
		cin >> r >> c;
		char map[30][30];
		memset(map,'.',sizeof(map));
		int i,j;
		for(i=1;i<=r;i++)
		{
			getchar();
			for(j=1;j<=c;j++)
				scanf("%c",&map[i][j]);
		}
		
		bool empty[30];
		memset(empty,true,sizeof(empty));
		empty[0] = false;
		empty[29] = false;
		for(i=1;i<=r;i++)
		{
			for(j=1;j<=c;j++)
			{
				if(map[i][j] != '?')
				{
					empty[i] = false;
					int tmp = j - 1;
					char put = map[i][j];
					while(map[i][tmp] == '?')
					{
						map[i][tmp] = put;
						tmp--;
					}
					
					j++;
					while(map[i][j] == '?')
					{
						map[i][j] = put;
						j++;
					}
					j--;
				}
			}
		}

		for(i=1;i<=r;i++)
		{
			if(empty[i] == false)
			{
				int tmp = i - 1;
				while(empty[tmp] == true)
				{
					for(j=1;j<=c;j++)
						map[tmp][j] = map[i][j];
					tmp--;
				}

				int tmpi = i;
				i++;
				while(empty[i] == true)
				{
					for(j=1;j<=c;j++)
						map[i][j] = map[tmpi][j];
					i++;
				}
				i--;
			}
		}
		
		printf("Case #%d:\n",++co);
		for(i=1;i<=r;i++)
		{
			for(j=1;j<=c;j++)
				printf("%c",map[i][j]);
			puts("");
		}
	}
	return 0;
}
