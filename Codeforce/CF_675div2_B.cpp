#include<iostream>
#include<algorithm>
using namespace std;

//int a[10] = {1,2,3,4,5,6,7,8,9,10};

int main()
{
    int n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    
    int tmp[4];
    tmp[0] = a+b;
    tmp[1] = b+d;
    tmp[2] = c+d;
    tmp[3] = c+a;
    
    sort(tmp,tmp+4);
    long long can = n - (tmp[3] - tmp[0]);
    if(can < 0)
        can = 0;
    
    cout << n*can << endl;
    
    return 0;
}
