1#include <stdio.h>
2#include <string.h>
3
4char ret_val[200];
5
6char* longestCommonPrefix(char** strs, int strsSize)
7{
8    if (strsSize == 0)
9        return "";
10
11    // Initialize prefix with the first string
12    strncpy(ret_val, strs[0], sizeof(ret_val) - 1);
13    ret_val[sizeof(ret_val) - 1] = '\0';
14
15    for (int i = 1; i < strsSize; i++)
16    {
17        int j = 0;
18
19        // Compare prefix with current string
20        while (ret_val[j] && strs[i][j] && ret_val[j] == strs[i][j])
21        {
22            j++;
23        }
24
25        // Cut prefix at first mismatch or string end
26        ret_val[j] = '\0';
27
28        // If prefix becomes empty, stop early
29        if (ret_val[0] == '\0')
30            break;
31    }
32
33    return ret_val;
34}
35