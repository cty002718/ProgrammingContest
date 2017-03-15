#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int m,n;
    cin >> m >> n;
    int i;
    int ans = 0;
    for(i=1;i<=m;i++)
        if(n%i==0 && n/i<=m)
            ans++;
    
    cout << ans << endl;
    return 0;
}
