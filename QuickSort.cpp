#include <iostream>

using namespace std;

void PrintArr(int *arr)
{
	for(int i=0; i <= 9; i++)
		cout<<arr[i]<<'\t';
	cout<<endl;
}
void swap(int &n1, int &n2)
{
	int temp = n1;
	n1 = n2;
	n2 = temp;
}

int Partition_Hoare(int *arr, int begin, int end)
{
	int low = begin;
	int high = end;
	int pivot = arr[low];

	while(low < high)
	{
		while( low < high && arr[high] >= pivot)
			--high;
		arr[low] = arr[high];

		while( low < high && arr[low] <= pivot)
			++low;
		arr[high] = arr[low];
	}
	arr[low] = pivot;
	return low;
}

int Partition_Normal(int *arr, int begin, int end)
{
	int low = begin - 1;
	int sentinel = arr[end];

	for(int high = begin ; high <= end - 1; ++high)
	{
		if(arr[high] <= sentinel)
		{
			low++;
			swap( arr[low], arr[high]);
		}
	}
	swap(arr[low+1], arr[end]);
	return low+1;
}

int Partition(int *arr, int begin, int end)
{
	int low = begin - 1;
	int sentinel = arr[end];

	for(int high = begin ; high <= end - 1; ++high)
	{
		if(arr[high] <= sentinel)
		{
			low++;
			swap( arr[low], arr[high]);
		}
	}
	swap(arr[low+1], arr[end]);
	return low+1;
}
int RandomPartition(int *arr, int begin, int end)
{
	int i = begin + rand() % (end - begin + 1);
	swap( arr[i], arr[end]);
	return Partition(arr, begin, end);
}
