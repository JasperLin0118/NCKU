#include<stdio.h>

int main ()
{
	int seat,who,move;
	scanf("%d %d %d",&seat,&who,&move);
	printf("%d", (who+move%seat)>=seat ? who+move%seat-seat : who+move%seat);
	return 0;
}
