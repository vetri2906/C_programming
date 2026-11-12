void swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void bubble_sort(int arr[], int size)
{
	for (int i = 0; i < size -1; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if(arr[i] > arr[j])
			{
				swap(&arr[i], &arr[j]);
			}
		}
	}
}
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int after_m = m;
    for (int i = 0; i<n; i++)
    {
        after_m = m + i;
        nums1[after_m] = nums2[i];
    }
    for (int i = 0; i<nums1Size; i++)
    {
       printf("%d", nums1[i]);
    }
    bubble_sort(nums1, nums1Size);
}