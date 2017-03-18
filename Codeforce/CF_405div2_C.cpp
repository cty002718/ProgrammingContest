#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

char put[53];
bool add[53];
char out[53];

int main()
{
	int n,k;
	cin >> n >> k;

	int i;
	for(i=1;i<=26;i++)
		put[i] = 'A' + i - 1;
	for(i=27;i<=52;i++)
		put[i] = 'A' + i - 27;
	
	for(i=1;i<k;i++)
	{
		out[i] = put[i];
		if(i > 26) add[i] = true;
	}
	
	int now = k;
	int j;
	for(j=k;j<=n;j++)
	{
		string tmp;
		cin >> tmp;
		if(tmp == "NO")
		{
			out[j] = out[j-k+1];
			add[j] = add[j-k+1];
		}
		else
		{
			if(now > 26) add[j] = true;
			else add[j] = false;
			out[j] = put[now++];
		}
	}

	for(i=1;i<=n;i++)
	{
		if(i!=1) cout << " ";
		cout << out[i];
		if(add[i]) cout << "a";
	}
	cout << endl;
	return 0;
}
