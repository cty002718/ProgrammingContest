#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

int check(string);

int main()
{
    string input;
    cin >> input;
   
    int i,j;
    for(i=0;i<26;i++)
        for(j=0;j<=input.size();j++)
		{
            string a = input;
            string b = " ";
            b[0] = i + 'a';
            a.insert(j,b);
            if(check(a))
            {
                cout << a << endl;
                exit(0);
            }
		}
    
    cout << "NA" << endl;
    
	return 0;
}

int check(string a)
{
    int i;
    for(i=0;i<a.size();i++)
        if(a[i]!=a[a.size()-i-1])
            return 0;
    return 1;
}
