#include<iostream>
#include<cstring>
using namespace std;

int n;
int solve(int);
int dir[5003];
int f[5003];

int main()
{
	int i;
	cin >> n;
	for(i=0;i<n;i++)
	{
		string tmp;
		cin >> tmp;
		if(tmp[0]=='B')
			dir[i]=1;
		else
			dir[i]=0;
	}	

	int ans=1e9;
	int ansk;
	for(i=1;i<=n;i++)
	{
		int tmp=solve(i);
		if(tmp==-1)
			continue;
		if(tmp<ans)
		{
			ans=tmp;
			ansk=i;
		}
	}

	cout << ansk << " " << ans << endl;
	return 0;
}

int solve(int k)
{
	memset(f,0,sizeof(f));
	int i;
	int sum=0;
	int ans=0;
	for(i=0;i+k-1<n;i++)
	{
		if(i-k>=0)
			sum-=f[i-k];
		if((sum+dir[i])&1)
		{
			f[i]=1;
			sum+=f[i];
			ans++;
		}
	}

	for(i=n-k+1;i<n;i++)
	{
		if(i-k>=0)
			sum-=f[i-k];
		if((sum+dir[i])&1)
			return -1;
	}

	return ans;
}
