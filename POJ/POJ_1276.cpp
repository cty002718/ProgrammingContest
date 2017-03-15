#include <iostream>
#include <deque>
#include <algorithm>
#include<cstring>
using namespace std;

struct Pack
{
    int sum, cost;
};

deque <Pack> q;
int F[100003];

int main()
{
	int V,N;
	while(cin >> V)
	{
		memset(F,0,sizeof(F));
    	cin >> N;
    	for (int i = 1; i <= N; i ++)
   		{
       		int p,w,c;
        	cin >> p >> w;
			c = w;
        	//p = min(p, V / w); 加速
        	for (int j = 0; j < w; j++)
        	{
            	q.clear();
            	for (int k = 0; k <= (V - j) / w; k++)
            	{
                	int y = F[k * w + j] - k * c;
                	while (q.size() && q.back().cost <= y) q.pop_back();
                	q.push_back((Pack){k, y});
                	if (q.front().sum < k - p) q.pop_front();
                	F[k * w + j] = q.front().cost + k * c;
         	   }
        	}
    	}
    	cout << F[V] << endl;
    }	
	return 0;
}
