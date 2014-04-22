void MergeArr(int *a, int first, int mid, int end, int *c)
{
	int i = first, m = mid; 
	int j = mid + 1, n = end;
	int k = 0;
	while(i <= m && j <= n)
	{
		if(a[i] < a[j])
			c[k++] = a[i++];
		else
			c[k++] = a[j++];
	}
	while(i <= m)
			c[k++] = a[i++];
	while(j <= n)
			c[k++] = a[j++];

	for(i = 0; i < k; i++)
		a[first + i] = c[i];
}

void MergeProcess(int *arr, int first, int last, int *temp)
{
	if(first < last)
	{
		int mid = (first + last) / 2;
		MergeProcess(arr, first, mid, temp);
		MergeProcess(arr, mid + 1, last, temp);
		MergeArr(arr, first, mid, last, temp);
	}
}

bool MergeSort(int *a, int n)
{
	int *p = new int [n];

	if(p == NULL)
		return false;

	MergeProcess(a, 0 , n-1, p);
	delete[] p;
	return true;
}
