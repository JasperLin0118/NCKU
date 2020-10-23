#include<stdio.h>

int main ()
{
	int a,b,c;
	scanf("%d %d %d",&a,%b,%c);
	if(a>=b && a>=c) printf("%d",b>c ? b : c);
	if(b>=a && b>=c) printf("%d",a>c ? a : c);
	if(c>=a && c>=b) printf("%d",a>b ? a : b);
	return 0;
}
