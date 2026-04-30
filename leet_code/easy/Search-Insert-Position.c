1/*
2Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
3
4You must write an algorithm with O(log n) runtime complexity.
5
6 
7
8Example 1:
9
10Input: nums = [1,3,5,6], target = 5
11Output: 2
12Example 2:
13
14Input: nums = [1,3,5,6], target = 2
15Output: 1
16Example 3:
17
18Input: nums = [1,3,5,6], target = 7
19Output: 4
20 
21
22Constraints:
23
241 <= nums.length <= 104
25-104 <= nums[i] <= 104
26nums contains distinct values sorted in ascending order.
27-104 <= target <= 104
28*/
29
30int searchInsert(int* nums, int numsSize, int target) {
31int start = 0;
32int end = numsSize;
33int mid = end/2;
34int retval;
35    while (end>0)
36    {
37        if (nums[mid] == target)
38        {
39            return mid;
40        }
41        else if (nums[mid] > target)
42        {
43            retval = mid;
44            end = mid;
45            mid = (end - start) / 2;
46            mid = start + mid;
47            // printf("\nxstart : %d xmid : %d xend : %d", start, mid, end);
48        }
49        else
50        {
51            retval = mid;
52            start = mid;
53            mid = (end - start) / 2;
54            mid = start + mid;
55        }
56        // printf("\nstart : %d mid : %d end : %d", start, mid, end);
57        if ((end - start) == 1)
58        {
59            if(nums[start] >= target)
60            retval = start;
61            else if (nums[mid] <= target)
62            retval = end;
63            else 
64            retval = mid;
65            end = 0;
66            break;
67        }
68    }
69    return retval;
70}