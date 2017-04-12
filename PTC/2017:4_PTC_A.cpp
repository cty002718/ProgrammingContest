#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<cstdlib>
#include<string>
#include<sstream>
using namespace std;

typedef long long ll;

struct bignum
{
	int minus;
	int number[503];
};

bignum tobig(int a)
{
	bignum tmp;
	if(a < 0)
	{
		tmp.minus = 1;
		a = -a;
	}
	else tmp.minus = 0;
	int c = 0;
	while(a)
	{
		tmp.number[c++] = a % 10;
		a/=10;
	}
	
	for(;c<503;c++)
		tmp.number[c] = 0;

	return tmp;
}


bignum mul(bignum& a, bignum& b)
{
	bignum tmp = tobig(0);
	int i,j;
	for(i=0;i<503;i++)
		for(j=0;j<503;j++)
			if(i+j > 500) continue;
			else tmp.number[i+j] += a.number[i] * b.number[j];
	
	for(i=0;i<502;i++)
	{
		tmp.number[i+1] += tmp.number[i]/10;
		tmp.number[i] %= 10;
	}

	if(a.minus == b.minus) tmp.minus = 0;
	else tmp.minus = 1;

	return tmp;
}

bool compare(bignum& a, bignum& b)
{
	int i;
	if(a.minus != b.minus)
	{
		if(a.minus == 1)
			return false;
		else
			return true;
	}
	for(i=502;i>=0;i--)
	{
		if(a.number[i] > b.number[i])
			return true;
		else if(a.number[i] < b.number[i])
			return false;
	}
	return false;
}

void printbig(bignum& ans)
{
	int i = 502;	
	while(ans.number[i] == 0 && i >= 0) i--;
	if(i == -1) printf("0\n");
	else
	{
		if(ans.minus == 1) printf("-");
		for(;i>=0;i--)
			printf("%d",ans.number[i]);
		puts("");
	}
}


int main()
{
	string input;
	while(getline(cin, input))
	{
		input = input + " 1000000";
		stringstream ss(input);
		int num;
		int c = 0;
		vector<int> v;
		int reverse = 0;
		bignum ans = tobig(-100000);
		
		while(ss >> num)
		{
			if(num == 0 || num == 1000000)
			{
				//cout << num << endl;
				//cout << reverse << endl;
				//if(v.size() == 0) continue;
				if(num == 0) c = 1;
				if(v.size() == 0) continue;
				if((reverse & 1) == 0)
				{
					int i;
					bignum anstmp = tobig(1);
					for(i=0;i<v.size();i++)
					{
						bignum tmp = tobig(v[i]);
						anstmp = mul(tmp, anstmp);
					//	printbig(anstmp);
					}	
					if(compare(anstmp, ans))
						ans = anstmp;
				}
				else
				{
					int i;
					int retmp = 0;
					bignum anstmp = tobig(1);
					int suc = 0;
					for(i=0;i<v.size();i++)
					{
						if(v[i] < 0) retmp++;
						if(retmp == reverse)
							break;
						suc = 1;
						bignum tmp = tobig(v[i]);
						anstmp = mul(anstmp, tmp);
					}

					//printbig(anstmp);
					if(suc == 1 && compare(anstmp, ans))
						ans = anstmp;
				  	//printbig(ans);	
					suc = 0;
					retmp = 0;
					anstmp = tobig(1);
					for(i=v.size()-1;i>=0;i--)
					{
						if(v[i] < 0) retmp++;
						if(retmp == reverse)
							break;
						suc = 1;
						bignum tmp = tobig(v[i]);
						anstmp = mul(anstmp, tmp);
					}
				    //printbig(ans);	
					//printbig(anstmp);
					if(suc == 1 && compare(anstmp, ans))
						ans = anstmp;
					
				}
				
				reverse = 0;
				v.clear();
			}
			else
			{
				if(num < 0) reverse++;
				bignum t = tobig(num);
				if(compare(t, ans))
					ans = t;
				v.push_back(num);
			}
		}

		if(c==1)
		{
			bignum c = tobig(0);
			if(compare(c, ans))
				ans = c;
		}
		
		printbig(ans);
	}
	
	return 0;
}
