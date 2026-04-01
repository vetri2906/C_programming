// #include <stdio.h>
// 2#include <string.h>
// 3
// 4char ret_val[200];
// 5
// 6char* longestCommonPrefix(char** strs, int strsSize)
// 7{
// 8    if (strsSize == 0)
// 9        return "";
// 10
// 11    // Initialize prefix with the first string
// 12    strncpy(ret_val, strs[0], sizeof(ret_val) - 1);
// 13    ret_val[sizeof(ret_val) - 1] = '\0';
// 14
// 15    for (int i = 1; i < strsSize; i++)
// 16    {
// 17        int j = 0;
// 18
// 19        // Compare prefix with current string
// 20        while (ret_val[j] && strs[i][j] && ret_val[j] == strs[i][j])
// 21        {
// 22            j++;
// 23        }
// 24
// 25        // Cut prefix at first mismatch or string end
// 26        ret_val[j] = '\0';
// 27
// 28        // If prefix becomes empty, stop early
// 29        if (ret_val[0] == '\0')
// 30            break;
// 31    }
// 32
// 33    return ret_val;
// 34}
38
39#include <stdio.h>
40#include <string.h>
41
42char ret_val[200];
43
44char* longestCommonPrefix(char** strs, int strsSize) {
45    memset(ret_val, 0, 200);
46
47    if (strsSize == 1)
48    {
49        return strs[0];
50    }
51
52    int a = 0;
53    int loop = 0;
54
55    // Initialize ret_val with first string
56    strncpy(ret_val, strs[0], 200);
57
58    for (; a < strsSize - 1; a++)
59    {
60        loop = 0;
61
62        while (strs[a][loop] && strs[a+1][loop] &&
63               strs[a][loop] == strs[a+1][loop])
64        {
65            loop++;
66        }
67
68        // 🔑 cap by existing prefix length
69        if (loop > strlen(ret_val))
70        {
71            loop = strlen(ret_val);
72        }
73
74        memset(ret_val, 0, 200);
75        strncpy(ret_val, strs[a], loop);
76        printf("ret %s loop val : %d\n", ret_val, loop);
77
78        // no common prefix → stop
79        if (loop == 0)
80        {
81            break;
82        }
83    }
84
85    return ret_val;
86}
87
88