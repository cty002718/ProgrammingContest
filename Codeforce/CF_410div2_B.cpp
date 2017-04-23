#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int i;
	char input[100][120];
	for(i=0;i<n;i++)
		scanf("%s",input[i]);	
	
	int len = 0;
	i = 0;
	while(input[0][i] != '\0') i++;
	len = i;
	
	int dis[100][100];
	memset(dis,0,sizeof(dis));

	int j,k;
	int suc2 = 1;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			char tmp[120];
			int m;
			for(m=0;m<120;m++)
				tmp[m] = input[i][m];
			if(i == j) continue;
			int left = 0, right = len;
			while(right <= len*2+1)
			{
				int suc = 1;
				for(k=left;k<right;k++)
					if(tmp[k] != input[j][k-left])
						suc = 0;

				if(suc == 1) break;
				tmp[right] = tmp[left];
				left++;
				right++;
			}

			if(right >=len*2+1) suc2 = 0;
			dis[i][j] = left;
		}
	
	int ans = 1e9;
	for(i=0;i<n;i++)
	{
		int sum = 0;
		for(j=0;j<n;j++)
			sum += dis[j][i];

		ans = min(ans, sum);
	}

	if(suc2) cout << ans << endl;
	else cout << -1 << endl;
	return 0;
}
