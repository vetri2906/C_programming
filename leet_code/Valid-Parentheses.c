1// #include <stdbool.h>
2// #include <string.h>
3
4// bool isValid(char* s) {
5//     int length = strlen(s);
6    
7//     // An odd length string can never be balanced
8//     if (length % 2 != 0) return false;
9
10//     // Stack to store expected closing characters
11//     char stack[length];
12//     int top = -1;
13
14//     for (int i = 0; i < length; i++) {
15//         char c = s[i];
16        
17//         // If we see an opening bracket, push the EXPECTED closing bracket onto the stack
18//         if (c == '(') {
19//             stack[++top] = ')';
20//         } else if (c == '{') {
21//             stack[++top] = '}';
22//         } else if (c == '[') {
23//             stack[++top] = ']';
24//         } 
25//         // If it's a closing bracket
26//         else {
27//             // If stack is empty or the top doesn't match current closing bracket, it's invalid
28//             if (top == -1 || stack[top] != c) {
29//                 return false;
30//             }
31//             top--; // Pop the stack
32//         }
33//     }
34
35//     // If top is -1, all brackets were matched correctly
36//     return top == -1;
37// }
38
39uint8_t open_or_close(char s)
40{
41    switch(s)
42    {
43        case '(':
44            return 1;
45        break;
46        case '{':
47            return 2;
48        break;
49        case '[':
50            return 3;
51        break;
52        case ')':
53            return 4;
54        break;
55        case '}':
56            return 5;
57        break;
58        case ']':
59            return 6;
60        break;
61        default:
62        break;
63    }
64    return 0;
65}
66
67bool isValid(char* s) {
68    bool retval;
69    uint32_t length = strlen(s);
70    if(( length == 0) || ( length == 1))
71    {
72        return false;
73        // nothing to compare
74    }
75    char buff[length];
76    uint8_t open = 0;
77    uint8_t close = 0;
78    uint32_t j = 0;
79    for(uint32_t i = 0; i<length; i++)
80    {
81        open = open_or_close(s[i]);
82        if(open<=3)
83        {
84            buff[j] = s[i];
85            j++;    
86        }
87        else
88        {
89            close = open;
90            if(j!=0)
91            {
92                j--;
93            }
94            open = open_or_close(buff[j]);
95            printf("open :%c close : %c", buff[j], s[i]);
96            if((open==1&&close==4)||(open==2&&close==5)||(open==3&&close==6))
97            {
98               retval = true;
99            }
100            else
101            {
102                retval = false;
103                return retval;
104            }
105            buff[j] = 0;
106        }
107    }
108    if(j>0)
109    {
110        retval = false;
111    }
112    return retval;
113}
114