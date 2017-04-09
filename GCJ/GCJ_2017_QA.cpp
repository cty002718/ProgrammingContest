#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstring>
using namespace std;

int main()
{
	int T;
	cin >> T;
	int c = 0;
	int i,j;
	while(T--)
	{
		string input;
		int m;
		cin >> input;
		cin >> m;
	
		int ans = 0;
		for(i=0;i<input.size()-m+1;i++)
			if(input[i] =='-')
			{
				ans++;
				for(j=i;j<i+m;j++)
					if(input[j] == '-') input[j] = '+';
					else input[j] = '-';
			}

		int suc = 1;
		for(i=0;i<input.size();i++)
			if(input[i] == '-') suc = 0;

		if(suc) printf("Case #%d: %d\n",++c,ans);
		else printf("Case #%d: IMPOSSIBLE\n",++c);
	}

	return 0;
}
