#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

typedef long long ll;
pair<ll,ll> p[100000];
long long sum1[100000];
long long sum2[100000];

int main()
{
	int n,c;
	long long f;
	cin >> n >> c >> f;
	
	int i;
	for(i=0;i<c;i++)
		scanf("%lld%lld",&p[i].first,&p[i].second);
	
	sort(p,p+c);

	priority_queue<ll> p1;
	priority_queue<ll> p2;
	long long ans=0;

	int shift=(n-1)/2;
	for(i=0;i<shift;i++)
	{
		sum1[shift]+=p[i].second;
		p1.push(p[i].second);
	}
	for(i=c-1;i>c-1-shift;i--)
	{
		sum2[c-1-shift]+=p[i].second;
		p2.push(p[i].second);
	}

	for(i=shift+1;i<=c-1-shift;i++)
	{
		sum1[i]=sum1[i-1]+p[i-1].second;
		p1.push(p[i-1].second);
		sum1[i]-=p1.top();
		p1.pop();
	}
	for(i=c-2-shift;i>=shift;i--)
	{
		sum2[i]=sum2[i+1]+p[i+1].second;
		p2.push(p[i+1].second);
		sum2[i]-=p2.top();
		p2.pop();
	}

	for(i=shift;i<=c-1-shift;i++)
		if(p[i].second+sum1[i]+sum2[i]<=f)
			ans=max(ans,p[i].first);
	
    if(ans!=0)
        cout << ans << endl;
	else
        cout << -1 << endl;
    return 0;
}
