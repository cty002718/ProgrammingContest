#include <iostream>
#include <deque>
#include <algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

struct Pack
{
    int sum, cost;
	Pack(int s,int t) : sum(s),cost(t) {}
};

deque <Pack> q;
int F[100003];

int main()
{
    int V,N;
    while(scanf("%d%d",&N,&V)!=EOF && N!=0 && V!=0)
    {
        memset(F,0,sizeof(F));
        int tmpp[103];
        int tmpw[103];
        for(int i=1;i<=N;i++)
            scanf("%d",&tmpw[i]);
		for(int i=1;i<=N;i++)
			scanf("%d",&tmpp[i]);
        
        for (int i = 1; i <= N; i ++)
        {
            int p,w,c;
            p = tmpp[i];
            w = tmpw[i];
            c = tmpw[i];
            p = min(p, V / w);
            for (int j = 0; j < w; j++)
            {
                q.clear();
                for (int k = 0; k <= (V - j) / w; k++)
                {
                    int y = F[k * w + j] - k * c;
                    while (q.size() && q.back().cost <= y) q.pop_back();
                    q.push_back(Pack(k, y));
                    if (q.front().sum < k - p) q.pop_front();
                    F[k * w + j] = q.front().cost + k * c;
                }
            }
        }
        int sum = 0;
        for(int i = 1;i<=V;i++)
        {
		//	cout << F[i] << " ";
			if(F[i] == i)
                sum++;
    	}
		//cout << endl;
		cout << sum << endl;
	}	
    return 0;
}
