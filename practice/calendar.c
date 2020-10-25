#include<stdio.h>
	
int y(int);		//ordinary=0,leap=1
int first(int,int);
int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int main ()
{
	int i,year,month,firstday;
	scanf("%d %d",&year,&month);
	firstday = first(year,month);
	if(y(year) == 1) day[1] = 29;
	else day[1] = 28;

	printf("Sun Mon Tue Wed Thu Fri Sat \n");
	for(i=0;i<firstday;i++) printf("    ");
	for(i=1;i <= day[month-1];i++)
	{
		printf("%3d ",i);
		if( (i+firstday)%7==0 && i!=day[month-1]) printf("\n");
	}
	return 0;
}

int y(int num)
{
	if(num % 4 != 0) return 0;
	if(num%100 == 0 && num%400 != 0) return 0;
	if(num % 400 == 0) return 1;
	if(num % 4 == 0) return 1;	
}

int first(int year,int month)
{
	int i=2020,j=0,mon=month,first=3;
	if(year >= 2020)
	{
		for(i=2020;i <= year;i++)
		{
			if(y(i) == 1) day[1] = 29;
			else day[1] = 28;
			month = (i==year) ? mon-1 : 12 ;
			for(j=0;j < month ;j++) first += day[j];

//			printf("%d\n",first);}
		}
	}

	if(year < 2020)
	{
		for(i=2020-1;i >= year;i--)
                {       
			if(y(i) == 1) day[1] = 29;
                        else day[1] = 28;
			month = (i==year) ? mon-1 : 0 ;
                        for(j=11;j >= month ;j--) first += day[j];

//			printf("%d\n",first);}
		}  
	}
	if(year >= 2020) return first%7;
	else if ( (first-3)%7>3) return 10-(first-3)%7;
       	     else return 3-(first-3)%7;
}
