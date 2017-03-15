#include<iostream>
#include<map>
#include<cstring>
using namespace std;

int main()
{
	int n;
	while(cin >> n && n!=0)
	{
		map<string,int> m;
		int i;
		int c=1;
		int din[1003];
		memset(din,0,sizeof(din));
		for(i=0;i<n;i++)
		{
			string a,b;
			cin >> a >> b;
			//cout << a << b << endl;
			//cout << m[a] << " " << m[b] << endl;
			if(m[a]==0)
				m[a]=c++;
			if(m[b]==0)
				m[b]=c++;

			din[m[b]]++;
		}
		
		//cout << c << endl;
		int num=0;
		for(i=1;i<c;i++)
			if(din[i]==0)
				num++;
		//cout << num << endl;
		if(num==1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
