#include<stdio.h>

int main ()
{
	int i,j,layer;
	scanf("%d", &layer);
	for(i=1;i <= layer;i++)
	{
		for(j=1;j <= layer-i;j++) printf(" ");
		for(j=0;j < 2*layer-1;j++) printf("*");
		printf("\n");	
	}
	return 0;
}
