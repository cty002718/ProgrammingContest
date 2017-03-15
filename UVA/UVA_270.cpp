#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#define pi 2*acos(0.0)
using namespace std;

double EPS = 1e-10;

int main()
{
	int T;
	cin >> T;
	getchar();
	getchar();
	while(T--)
	{
        char buf[800];
		pair<double,double> P[800];
		int c=0;
        while (gets(buf) && buf[0]) {
            sscanf(buf, "%lf%lf", &P[c].first,&P[c].second);
            c++;
        }

		int i;
		int ans = 0;
		for(i=0;i<c;i++)
		{
			vector<double> v;
			int j;
			for(j=0;j<c;j++)
				if(i!=j)
				{
					double x = P[j].first - P[i].first;
					double y = P[j].second - P[i].second;
					double tmp = atan(y/x);
					if(P[j].second - P[i].second < EPS)
						tmp+=pi;
					v.push_back(tmp); 
				}

			sort(v.begin(),v.end());
			vector<double>::iterator iter;
			
			int tmpans = 2;
			for(iter=v.begin()+1;iter!=v.end();iter++)
				if(*iter - *(iter-1) < EPS)
					tmpans++;
				else
				{
					ans = max(ans,tmpans);
					tmpans = 2;
				}

			ans = max(ans,tmpans);
		}
		
		cout << ans << endl;
		if(T!=0)
			cout << endl;
		//cout << "hihihi" << endl;
	}
	return 0;
}
