void quicksort(int a[], int low, int high) 
{    
	if(high > low)
	{
		int pivot=low, i=low+1, j=high;
		while(j >= i)
		{
			while(a[i] <= a[pivot] && i <= high) i++;
			while(a[j] >= a[pivot] && j > low) j--;
			if(j >= i) a[i] ^= a[j] ^= a[i] ^= a[j];
		}
        	a[pivot] ^= a[j] ^= a[pivot] ^= a[j];
	
       		quicksort(a,j+1,high);
		quicksort(a,low,j-1);
	}
}

