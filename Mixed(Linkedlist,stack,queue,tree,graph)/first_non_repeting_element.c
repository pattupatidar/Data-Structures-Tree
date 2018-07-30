#include<stdio.h>
#include<string.h>
void by_simple_way(char ch[],int count[],int l)
{
	//===================================
	int i;	
	for(i=0;i<26;i++)
	{
		count[i]=0;
	}
	printf("\n c-ount array is :\n");
	for(i=0;i<26;i++)
	{
		printf("%d ",count[i]);
	}
	printf("\n");
	for(i=0;i<l;i++)
	{
		count[ch[i]-'A']++;
	}
	printf("\n count array is :\n");
	for(i=0;i<26;i++)
	{
		printf("%d ",count[i]);
	}
	for(i=0;i<l;i++)
	{
		if(count[ch[i]-'A']==1)
		{
			printf("\n First nonr-epeating character in the given string  is %c",ch[i]);
			break;
		}
	}
	if(i==l)
	{
		printf("\n No Non repeting element present in the given string::");
	}
}
void by_best_way(char ch[],int count[],int l)
{
	int i;	
	for(i=0;i<26;i++)
	{
		count[i]=-1;
	}
	printf("\n count array is :\n");
	for(i=0;i<26;i++)
	{
		printf("%d ",count[i]);
	}
	printf("\n");
	for(i=0;i<l;i++)
	{
		if(count[ch[i]-'A']==-1)
		{
			count[ch[i]-'A']=i;
		}
		else
		{
			count[ch[i]-'A']=-2;
		}
	}
	printf("\n New count array is :\n");
	for(i=0;i<26;i++)
	{
		printf("%d ",count[i]);
	}
	int min=0;
	for(i=0;i<26;i++)
	{
		if(count[i]>=0)
		{
				if(min>=count[i])
				{
					min=count[i];
				}
		}
	}
	printf(" \nfirst non repeting element in the given string is %c",ch[min]);
}
int main()
{
	
	printf("\n Enter a string  :");
	char ch[100];
	scanf("%s",&ch);
	int l = strlen(ch);
	int i;
	printf("\n Entered string is : ");
	for(i=0;i<l;i++)
	{
		printf("%c ",ch[i]);
	}
	int count[26];
	by_simple_way(ch,count,l);
	printf("\n\n");
	by_best_way(ch,count,l);
	return 0;
}
