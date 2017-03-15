#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n,s;
	int i;
	cin >> n >> s;

	int price,num;
	cin >> price >> num;
	long long ans=price*num;
	int now=price;
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&price,&num);
		if(price<now+s)
			now=price;
		else
			now+=s;

		ans+=now*num;
	}

	cout << ans << endl;
	

	return 0;
}
