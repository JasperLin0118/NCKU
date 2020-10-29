#include<stdio.h>

int main ()
{
	char words[180];
	scanf("%[^\n]",words);
	for(int i=0;words[i] != '\0';i++)
	{
		if(words[i]==' ' && words[i+1]!=' ') printf(" ");
		if(words[i]!=' ') printf("%c", words[i]);       	
	}
	return 0;
}
