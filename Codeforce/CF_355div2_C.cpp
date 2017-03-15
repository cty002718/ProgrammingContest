#include<iostream>
#include<cstdio>
#include<cstring>
#define  mod 1000000007;
using namespace std;

int main()
{
	int i,j;
	int bin[10];
	long long ans[100];
	for(i=0;i<100;i++)
		ans[i]=1;
	int tmp;
	for(i=0;i<64;i++)
	{
		memset(bin,0,sizeof(bin));
		tmp=i;
		int c=0;
		while(tmp)
		{
			bin[c++]=tmp%2;
			tmp/=2;
		}

		for(j=0;j<=5;j++)
			if(bin[j]==0)
				ans[i]*=3;
	}
	
//	for(i=0;i<64;i++)
//		cout << ans[i] << " ";
//	cout << endl;
	string input;
	cin >> input;
	long long sum=1;
	for(i=0;i<input.size();i++)
	{
		int num;
		if(input[i]>='0' && input[i]<='9')
			num=input[i]-'0';
		else if(input[i]>='A' && input[i]<='Z')
			num=input[i]-'A'+10;
		else if(input[i]>='a' && input[i]<='z')
			num=input[i]-'a'+36;
		else if(input[i]=='-')
			num=62;
		else
			num=63;
		
		//cout << ans[num] << endl;
		sum=(sum*ans[num])%mod;
	}

	cout << sum << endl;

	return 0;
}
