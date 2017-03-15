#include<iostream>
using namespace std;

int main()
{
	long long c[22][22];
	int i,j;
	c[0][0]=1;
	for(i=1;i<22;i++)
	{
		c[i][0]=1;
		c[0][i]=0;
	}
	
	for(i=1;i<=20;i++)
		for(j=1;j<=20;j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	
	int a,b;
	while(cin >> a >> b && a!=-1)
	{
		cout << a << "+" << b;
		if(c[a+b][a]==a+b)
			cout << "=" << a+b;
		else
			cout << "!=" << a+b;

		cout << endl;
	}
	return 0;
}
