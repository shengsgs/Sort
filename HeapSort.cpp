void Heapify(int *a, int i, int size)
{
	int larger; 
	int l_t = 2*i;
	int r_t = 2*i + 1;
	if(a[l_t] > a[i] && l_t <=size)
		larger = l_t;
	else 
		larger = i;
    if(a[r_t] > a[larger] && r_t <=size)
		larger = r_t;
	if(i != larger)
	{
		swap(a[i], a[larger]);
		Heapify(a, larger, size);
	}
}

void BuildHeap(int *arr, int len)
{
	for(int i = len/2; i > 0; --i)
		Heapify(arr, i, len);
}
