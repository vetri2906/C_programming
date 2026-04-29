1/*
226. Remove Duplicates from Sorted Array
3
4Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.
5
6Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.
7
8The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.
9
10Custom Judge:
11
12The judge will test your solution with the following code:
13
14int[] nums = [...]; // Input array
15int[] expectedNums = [...]; // The expected answer with correct length
16
17int k = removeDuplicates(nums); // Calls your implementation
18
19assert k == expectedNums.length;
20for (int i = 0; i < k; i++) {
21    assert nums[i] == expectedNums[i];
22}
23If all assertions pass, then your solution will be accepted.
24
25 
26
27Example 1:
28
29Input: nums = [1,1,2]
30Output: 2, nums = [1,2,_]
31Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
32It does not matter what you leave beyond the returned k (hence they are underscores).
33Example 2:
34
35Input: nums = [0,0,1,1,1,2,2,3,3,4]
36Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
37Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
38It does not matter what you leave beyond the returned k (hence they are underscores).
39 
40
41Constraints:
42
431 <= nums.length <= 3 * 104
44-100 <= nums[i] <= 100
45nums is sorted in non-decreasing order.
46*/
47
48void shift_once_left(int* nums, int numsSize)
49{
50    for (int i = 0; i < numsSize - 1; i++)
51    {
52        nums[i] = nums[i+1];
53    }
54}
55
56int removeDuplicates(int* nums, int numsSize) {
57    int counter = 0;
58    int retval = 0;
59    int loop_size = numsSize;
60    for (int i = 0; i < loop_size -1; i++)
61    {
62        // printf("\n%d",nums[i]);
63        for (int j = i+1; j < loop_size; j++)
64        {
65            // printf("\n%d , %d", i, j);
66            if(nums[i] == nums[j])
67            {
68                // printf("\n%d , %d", nums[i], nums[j]);
69                shift_once_left(&nums[j], loop_size - j);
70                loop_size--;
71                j--;
72                counter++;
73            }
74        }
75    }
76    retval = numsSize - counter;
77    // printf("\n%d, %d",numsSize, counter);
78    return retval;
79}