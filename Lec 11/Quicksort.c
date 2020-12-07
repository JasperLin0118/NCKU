void quicksort(int a[], int low, int high) 
{    
	if(high > low)
	{
		int pivot=low, i=low+1, j=high;
		while(j >= i)
		{
			while(a[i] <= a[pivot] && i <= high) i++;
			while(a[j] >= a[pivot] && j > low) j--;
			if(j >= i) int tmp=a[i], a[i]=a[j], a[j]=tmp;	//swap
		}
        	int tmp=a[pivot], a[pivot]=a[j], a[j]=tmp;	//swap
	
       		quicksort(a,j+1,high);
		quicksort(a,low,j-1);
	}
}

