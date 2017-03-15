#include<cstdio>
#include<cstring>
#include<set>
#include<iostream>
using namespace std;

int grundy(int);
int input[1003];
int sg[1003];
int m;
int k;

int main()
{
	int n;
	while(cin >> n >> k)
	{
		int i;
		int ans = 0;
		for(i=0;i<n;i++)
		{
			memset(sg,-1,sizeof(sg));
			cin >> m;
			int j;
			for(j=0;j<m;j++)
				cin >> input[j];

			ans^=(grundy(m-1));	
		}

		if(ans==0)
			cout << "Bob will win." << endl;
		else
			cout << "Alice can win." << endl;
		
		
		 
	}
	return 0;
}

int grundy(int x) {
    if(sg[x]!=-1)
		return sg[x];

	set<int> s;
    for (int j = 0; j <= k && x-j >= 0; j++)
    {
		int newx = x - input[x-j] - j;
		if(newx==-1)
			s.insert(0);
		else if(newx>=0)
    		s.insert(grundy(newx));
    }
    int g = 0;
    while (s.count(g)) g++;
    sg[x] = g;
    return g;
}
