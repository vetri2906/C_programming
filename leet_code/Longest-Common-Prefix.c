1// #include <stdio.h>
2// #include <string.h>
3
4// char ret_val[200];
5
6// char* longestCommonPrefix(char** strs, int strsSize) {
7//     memset((char*)ret_val, 0, 200);
8//     if(strsSize == 1)
9//     {
10//         return strs[0];
11//     }
12//     int a = 0;
13//     int loop = 0;
14//     for(; a < strsSize - 1; a++)
15//     {
16//         for(; (strs[a][loop] != 0 ) && (strs[a+1][loop] != 0 ); loop++)
17//         {
18//             if(strs[a][loop] == strs[a+1][loop])
19//             {
20//                 printf("1st byte %c top array : %d \n", strs[a][loop], a);
21//                 printf("compared with %c next array : %d \n", strs[a+1][loop], a+1);
22//             }
23//             else
24//             {
25//                 memset((char*)ret_val, 0, 200);
26//                 strncpy(ret_val, strs[a], loop); 
27//                 printf("ret %s loop val : %d\n", ret_val, loop);
28//                 break;
29//             }
30//         }
31//         memset((char*)ret_val, 0, 200);
32//         strncpy(ret_val, strs[a], loop); 
33//         printf("ret %s loop val : %d\n", ret_val, loop);
34//         loop = 0;
35//     }
36//     return ret_val;
37// }
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