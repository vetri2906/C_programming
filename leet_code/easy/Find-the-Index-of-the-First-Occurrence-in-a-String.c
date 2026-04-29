1/*
2Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
3
4 
5
6Example 1:
7
8Input: haystack = "sadbutsad", needle = "sad"
9Output: 0
10Explanation: "sad" occurs at index 0 and 6.
11The first occurrence is at index 0, so we return 0.
12Example 2:
13
14Input: haystack = "leetcode", needle = "leeto"
15Output: -1
16Explanation: "leeto" did not occur in "leetcode", so we return -1.
17 
18
19Constraints:
20
211 <= haystack.length, needle.length <= 104
22haystack and needle consist of only lowercase English characters.
23*/
24
25int strStr(char* haystack, char* needle) {
26    int haystack_length = strlen(haystack);
27    int needle_length = strlen(needle);
28    if(haystack_length < needle_length)
29    {
30        return -1;
31    }
32    int length_difference = haystack_length - needle_length;
33    int retval = 0;
34    for(int i = 0; i <= length_difference; i++)
35    {
36        retval = 0;
37        for(int j =0 ; j < needle_length; j++)
38        {
39            if(haystack[j] == needle[j])
40            {
41                retval++;
42            }
43            else
44            {
45                retval = -1;
46                haystack++;
47                break;
48            }
49        }
50        // printf("\nretval %d , needle length %d, length difference : %d", retval, needle_length, length_difference);
51        if(retval == needle_length)
52        {
53            retval = i;
54            break;
55        }
56        else
57        {
58            retval = -1;
59        }
60        // printf("\nretval %d , needle length %d", retval, needle_length);
61    }
62    return retval;
63}