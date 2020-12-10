void check_sudodu(int (*grid_p)[NUM])					//equal to int grid_p[NUM][NUM}
{
	for(int i=0;i<NUM;i++)						//scan all element
	{
		for(int j=0;j<NUM;j++)
		{
			for(int k=0;k<NUM;k++)				//row test
			{
				if(k == j) continue;
				if(grid[i][j]==gird[k][j]) printf("(%d,%d)\n", i, j);
			}

			for(int k=1;k<NUM;k++)
		}
	}
}
