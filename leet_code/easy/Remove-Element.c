1int removeElement(int* nums, int numsSize, int val) {
2    int ret_val = 0;
3    int new_nums[100];
4    uint32_t j = 0;
5    for (uint32_t i = 0; i< numsSize; i++)
6    {
7        if(nums[i] != val)
8        {
9            new_nums[j] = nums[i];
10            j++;
11            ret_val++;
12        }
13    }
14    for (uint32_t i = 0; i< ret_val; i++)
15    {
16        nums[i] = new_nums[i];
17    }
18 return ret_val;
19}