#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
using namespace std;

int sg(int);

int main()
{
    int n,k;
    cin >> n >> k;
    int i;
    int ans = 0;
    for(i=0;i<n;i++)
    {
        int tmp;
		int tmp2;
		cin >> tmp;
        if(k&1)
        {
           tmp2 = sg(tmp); 
        }
        else
        {
            if(tmp<=2) tmp2 = tmp; 
            else if(tmp&1) tmp2 = 0;
			else tmp2 = 1;
        }
        
   		//cout << i << " " <<  tmp2 << endl;
        ans^=tmp2;
    }
    
    if(ans==0)
        cout << "Nicky" << endl;
    else
        cout << "Kevin" << endl;
}

int sg(int tmp)
{
	 if(tmp==0) return 0;
     else if(tmp==1 || tmp==3) return 1;
     else if(tmp&1) return 0;
     else if(tmp==2) return 0;
     else if(tmp==4 || tmp==6) return 2;
	 else
     {
		if(sg(tmp/2)==2 || sg(tmp/2)==0) return 1;
		else return 2;
	 }
}
