#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>
using namespace std;

int sg[1003];
int fib[15] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987};
int grundy(int x);

int main()
{
	memset(sg,-1,sizeof(sg));
    sg[0] = 0;
	int i;
	for(i=1;i<=1000;i++)
        grundy(i);

	int a,b,c;
	while(cin >> a >> b >> c && a!=0 && b!=0 && c!=0)
	{	
		int ans = sg[a]^sg[b]^sg[c];
		if(ans==0)
			cout << "Nacci" << endl;
		else
			cout << "Fibo" << endl;
	}	

	return 0;
}

int grundy(int x) {
    if(sg[x]!=-1)
        return sg[x];
    
    set<int> s;
    int j;
    for (j=0;j<15;j++)
        if(x-fib[j] >= 0)
            s.insert(sg[x-fib[j]]);
    
    int g = 0;
    while (s.count(g)) g++;
    sg[x] = g;
    return g;
}
