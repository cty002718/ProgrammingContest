#include<iostream>
using namespace std;

int main()
{
	int a1,a2,a3,a4,a5,a6;
	while(cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6)
	{
		if(!a1&&!a2&&!a3&&!a4&&!a5&&!a6)
			break;
		
		int ans=a6+a5+a4;
		a1=max(0,a1-a5*11);
		
		if(a4*5<=a2)
			a2-=a4*5;
		else
		{
			int tmp=a4*5-a2;
			a2=0;
			a1=max(0,a1-tmp);
		}
        
       /* cout << ans << endl;
        cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<" "<<a5<<" "<<a6<<endl;
        */
        int tmp=a3%4;
		ans+=a3/4;
		ans++;
		if(tmp==0)
			ans--;
		else if(tmp==1)
		{
			if(a2<=5)
			{
				a1=max(0,a1-(27-a2*4));
				a2=0;
			}
			else
            {
				a2-=5;
                a1=max(0,a1-7);
            }
        }

		else if(tmp==2)
		{
			if(a2<=3)
			{
				a1=max(0,a1-(18-a2*4));
				a2=0;
			}
			else
            {
				a2-=3;
                a1=max(0,a1-6);
            }
        }

		else if(tmp==3)
		{
			if(a2<=1)
			{
				a1=max(0,a1-(9-a2*4));
				a2=0;
			}
			else
            {
                a2--;
                a1=max(0,a1-5);
            }
		}
		
		/*cout << ans << endl;
        cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<" "<<a5<<" "<<a6<<endl;
        */
        tmp=a2%9;
		ans+=a2/9;
		ans++;
		if(tmp==0)
			ans--;
		else
			a1=max(0,a1-(36-tmp*4));
		
		/*cout << ans << endl;
        cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<" "<<a5<<" "<<a6<<endl;
        */
		tmp=a1%36;
		ans+=a1/36;
		ans++;
		if(tmp==0)
			ans--;

		cout << ans << endl;
		//cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<" "<<a5<<" "<<a6<<endl;
	}

	return 0;
}
