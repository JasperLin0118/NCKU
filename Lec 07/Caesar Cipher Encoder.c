#include<stdio.h>

int main ()
{
	int move;
	char ch;

	scanf("%d", &move);
	move = (move<0) ? move%26+26 : move%26;

	while( scanf("%c", &ch) != EOF ) 
	{
		if(ch>='A' && ch<='Z') printf("%c",'A'+(ch-'A'+move)%26;
		if(ch>='a' && ch<='z') printf("%c",'a'+(ch-'a'+move)%26;
	}
	return 0;
}
