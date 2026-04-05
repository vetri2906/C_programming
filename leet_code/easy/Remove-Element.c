1/*
2Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.
3
4Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
5
6Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
7Return k.
8Custom Judge:
9
10The judge will test your solution with the following code:
11
12int[] nums = [...]; // Input array
13int val = ...; // Value to remove
14int[] expectedNums = [...]; // The expected answer with correct length.
15                            // It is sorted with no values equaling val.
16
17int k = removeElement(nums, val); // Calls your implementation
18
19assert k == expectedNums.length;
20sort(nums, 0, k); // Sort the first k elements of nums
21for (int i = 0; i < actualLength; i++) {
22    assert nums[i] == expectedNums[i];
23}
24If all assertions pass, then your solution will be accepted.
25
26 
27
28Example 1:
29
30Input: nums = [3,2,2,3], val = 3
31Output: 2, nums = [2,2,_,_]
32Explanation: Your function should return k = 2, with the first two elements of nums being 2.
33It does not matter what you leave beyond the returned k (hence they are underscores).
34Example 2:
35
36Input: nums = [0,1,2,2,3,0,4,2], val = 2
37Output: 5, nums = [0,1,4,0,3,_,_,_]
38Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
39Note that the five elements can be returned in any order.
40It does not matter what you leave beyond the returned k (hence they are underscores).
41 
42
43Constraints:
44
450 <= nums.length <= 100
460 <= nums[i] <= 50
470 <= val <= 100
48*/
49
50int removeElement(int* nums, int numsSize, int val) {
51    int ret_val = 0;
52    int new_nums[100];
53    uint32_t j = 0;
54    for (uint32_t i = 0; i< numsSize; i++)
55    {
56        if(nums[i] != val)
57        {
58            new_nums[j] = nums[i];
59            j++;
60            ret_val++;
61        }
62    }
63    for (uint32_t i = 0; i< ret_val; i++)
64    {
65        nums[i] = new_nums[i];
66    }
67 return ret_val;
68}