#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int consume[5];
	int i;
	for(i=1;i<=4;i++)
		scanf("%d",&consume[i]);

	char s[100003];
	int len;
	scanf("%s",s);
	len = strlen(s);
	
	int sum=0;
	for(i=0;i<len;i++)
		sum+=consume[s[i]-'0'];
	
	printf("%d\n",sum);
	return 0;
}
