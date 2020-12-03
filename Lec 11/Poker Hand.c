#include<stdio.h>
#define people 4
#define cards 5

void sort(int ranks[people+1][cards+1],int suits[people+1][cards+1], int person)
{
	for(int i=1;i<=cards;i++)
    	{
       	        for(int j=i+1;j<=cards+1;j++)
       	        {
       	              if(ranks[person][j]<ranks[person][i]) 
		      {
			      ranks[person][j] ^= ranks[person][i] ^= ranks[person][j] ^= ranks[person][i];
			      suits[person][j] ^= suits[person][i] ^= suits[person][j] ^= suits[person][i];
		      }
       	        }
   	}
}

int straight(int ranks[people+1][cards+1], int person)
{
	sort(ranks, suits, person);
	
	for(int i=1;i<cards;i++)
	{
		if(ranks[person][i]+1 != ranks[person][i+1]) return 0;
	}

	return 1;
}

int flush(int suits[people+1][cards], int person)	//same flower
{
	for(int i=1;i<cards;i++)
	{
		if(suits[person][i] != suits[person][i+1]) return 0;
	}
	return 1;
}

int four_of_a_kind(int ranks[people+1][cards+1], int person)
{
	sort(ranks, suits, person);

	if(ranks[person][2]==ranks[person][3] && ranks[person][3]==ranks[person][4])
	{
		if(ranks[person][1]==ranks[person][2] && ranks[person][5]!=ranks[person][2]) return 1;
                if(ranks[person][1]!=ranks[person][2] && ranks[person][5]==ranks[person][2]) return 1;
	}
	return 0;
}

int full_house(int ranks[people+1][cards+1], int person)
{
	sort(ranks,suits,person);

	if(ranks[person][1]==ranks[person][2]&&ranks[person][2]==ranks[person][3] && ranks[person][4]==rands[person][5])
		return 1;
        if(ranks[person][3]==ranks[person][4]&&ranks[person][4]==ranks[person][5] && ranks[person][1]==rands[person][2])
		return 1;
	return 0;
}

int three_of_a_kind(int ranks[people+1][cards+1], int suits[people+1][cards+1], int person)
{
	sort(ranks,suits,person);

        if(ranks[person][1]==ranks[person][2]&&ranks[person][2]==ranks[person][3] && ranks[person][4]!=rands[person][5])
		return 1;
        if(ranks[person][2]==ranks[person][3]&&ranks[person][3]==ranks[person][4] && ranks[person][1]!=rands[person][5])
		return 1;
        if(ranks[person][3]==ranks[person][4]&&ranks[person][4]==ranks[person][5] && ranks[person][1]==rands[person][2])
		return 1;

	return 0;
}

int two_pair(int ranks[people+1][cards+1], int person)
{
	sort(ranks,suits,person);

	if(ranks[person][1]==ranks[person][2] && ranks[person][3]==ranks[person][4]) return 1;
        if(ranks[person][2]==ranks[person][3] && ranks[person][4]==ranks[person][5]) return 2;
        if(ranks[person][1]==ranks[person][2] && ranks[person][4]==ranks[person][5]) return 3;

	return 0;
}

int pair(int ranks[people+1][cards+1], person)
{
	sort(ranks,suits,person);

	if(ranks[person][1] == ranks[person][2]) return 1;
        if(ranks[person][2] == ranks[person][3]) return 2;
        if(ranks[person][3] == ranks[person][4]) return 3;
        if(ranks[person][4] == ranks[person][5]) return 4;
	
	return 0;	
}


int main()
{
	int ranks[people+1][cards+1], suits[people+1][cards+1];
	int ans[people+1][4]; 

	for(int i=1;i<=people;i++)
	{
		for(int j=1;j<=cards;j++)
		{
			char r, s;

			if(j!=cards) scanf("%c%c ", &r, &s);
			else scanf("%c%c\n", &r, &s);

			switch(r)
			{
				case 't': ranks[i][j] = 10;
				 break;
				case 'j': ranks[i][j] = 11;
			 	 break;
				case 'q': ranks[i][j] = 12;
				 break;
				case 'k': ranks[i][j] = 13;
				 break;
				case 'a': ranks[i][j] = 14;
			 	 break;
				default: ranks[i][j] = r-48;
				 break;
			}
			switch(s)
			{
                                case 'c': suits[i][j] = 1;
                                 break;
                                case 'd': suits[i][j] = 2;
                                 break;
                                case 'h': suits[i][j] = 3;
                                 break;
                                case 's': suits[i][j] = 4;
                                 break;
			}

		}
	}

	for(int i=1;i<=people;i++)
	{
		if(straight(ranks,i)==1 && flush(suits,i)==1) 			//straight flush
		{
			ans[i][1] = 9;
			ans[i][2] = ranks[i][1];
			ans[i][3] = suits[i][1];
		}

		else if(four_of_a_kind(ranks,i) == 1)				//four-of-a-kind
		{
			ans[i][1] = 8;
			ans[i][2] = ranks[i][3];
		}

		else if(full_house(ranks,i) == 1)				//full-house
		{
			ans[i][1] = 7;
			ans[i][2] = ranks[i][3];
		}
		
		else if(flush(suits,i) == 1) 					//flush
		{
			ans[i][1] = 6;
			ans[i][2] = suits[i][1];
		}

		else if(straight(ranks,i) == 1)					//straight
		{
			ans[i][1] = 5;
			ans[i][2] = ranks[i][1];
		}
		
		else if(three_of_a_kind(ranks,suits,i) == 1)			//three-of-a-kind
		{
			ans[i][1] = 4;
			ans[i][2] = ranks[i][3];
		}

		else if(two_pair(ranks,i) > 0)					//two-pair
		{
			int tmp=two_pair(ranks,i);
			ans[i][1] = 3;
			if(tmp == 1) 
			{
				if(ranks[i][1]>ranks[i][3]) 
				{
					ans[i][2] = ranks[i][1];
					ans[i][3] = (suits[i][1]>suits[i][2]) ? suits[i][1] : suits[i][2];
				}
				else
				{
					ans[i][2] = ranks[i][3];
					ans[i][3] = (suits[i][3]>suits[i][4]) ? suits[i][3] : suits[i][4];
				}
			}
                        if(tmp == 2)
                        {
                                if(ranks[i][2]>ranks[i][4])
                                {
                                        ans[i][2] = ranks[i][2];
                                        ans[i][3] = (suits[i][2]>suits[i][3]) ? suits[i][2] : suits[i][3];
                                }
                                else
                                {
                                        ans[i][2] = ranks[i][4];
                                        ans[i][3] = (suits[i][4]>suits[i][5]) ? suits[i][4] : suits[i][5];
                                }
                        }
			if(tmp == 3)
                        {
                                if(ranks[i][1]>ranks[i][4])
                                {
                                        ans[i][2] = ranks[i][1];
                                        ans[i][3] = (suits[i][1]>suits[i][2]) ? suits[i][1] : suits[i][2];
                                }
                                else
                                {
                                        ans[i][2] = ranks[i][4];
                                        ans[i][3] = (suits[i][4]>suits[i][5]) ? suits[i][4] : suits[i][5];
                                }
                        }
		}

		else if(pair(ranks,i) > 0) 						//pair
		{
			int tmp=pair(ranks,i);
			ans[i][1] = 2;
			if(tmp == 1)
                                ans[i][2] = (suits[i][1]>suits[i][2]) ? suits[i][1] : suits[i][2];
                        if(tmp == 2)
                                ans[i][2] = (suits[i][2]>suits[i][3]) ? suits[i][2] : suits[i][3];
                        if(tmp == 3)
                                ans[i][2] = (suits[i][3]>suits[i][4]) ? suits[i][3] : suits[i][4];
                        if(tmp == 4)
                                ans[i][2] = (suits[i][4]>suits[i][5]) ? suits[i][4] : suits[i][5];			
		}

		else 
		{
			sort(ranks,suits,i);

			ans[i][1] = 1;
			ans[i][2] = ranks[i][5];
		}
	}



/*	 for(int i=1;i<=people;i++)
	 {
                for(int j=1;j<=cards;j++) printf("%d %d\t", ranks[i][j], suits[i][j]);
		puts("");
	 }
*/
}
