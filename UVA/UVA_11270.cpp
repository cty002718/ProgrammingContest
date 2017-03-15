#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long LL;
LL dp[2][1<<11];
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int main(){
    int n,m,i,j,k,tmp;
    while(cin >>n >>m){
        if(n < m) swap(&n,&m);
        memset(dp,0,sizeof(dp));
        dp[0][(1<<m)-1] = 1;
        int judL,judu;
        int now = 0, pre = 1;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                swap(&now,&pre);
                memset(dp[now],0,sizeof(dp[now]));
                
                for(k=0;k<(1<<m);k++){
                    if((k<<1)&(1<<m)) dp[now][(k<<1)^(1<<m)] += dp[pre][k];
                    if(i && !(k&(1<<(m-1))))
                        dp[now][(k<<1)^1] += dp[pre][k];
                    if(j && !(k&1) && k&(1<<(m-1)) )
                        dp[now][(k<<1)^(1<<m)^3] += dp[pre][k];
                }
            }
        }
        cout << dp[now][(1<<m)-1] <<endl;
    }
    return 0;
}
