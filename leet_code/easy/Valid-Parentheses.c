1/*
2Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
3
4An input string is valid if:
5
6Open brackets must be closed by the same type of brackets.
7Open brackets must be closed in the correct order.
8Every close bracket has a corresponding open bracket of the same type.
9 
10
11Example 1:
12
13Input: s = "()"
14
15Output: true
16
17Example 2:
18
19Input: s = "()[]{}"
20
21Output: true
22
23Example 3:
24
25Input: s = "(]"
26
27Output: false
28
29Example 4:
30
31Input: s = "([])"
32
33Output: true
34
35Example 5:
36
37Input: s = "([)]"
38
39Output: false
40
41 
42
43Constraints:
44
451 <= s.length <= 104
46s consists of parentheses only '()[]{}'.
47*/
48
49// #include <stdbool.h>
50// #include <string.h>
51
52// bool isValid(char* s) {
53//     int length = strlen(s);
54    
55//     // An odd length string can never be balanced
56//     if (length % 2 != 0) return false;
57
58//     // Stack to store expected closing characters
59//     char stack[length];
60//     int top = -1;
61
62//     for (int i = 0; i < length; i++) {
63//         char c = s[i];
64        
65//         // If we see an opening bracket, push the EXPECTED closing bracket onto the stack
66//         if (c == '(') {
67//             stack[++top] = ')';
68//         } else if (c == '{') {
69//             stack[++top] = '}';
70//         } else if (c == '[') {
71//             stack[++top] = ']';
72//         } 
73//         // If it's a closing bracket
74//         else {
75//             // If stack is empty or the top doesn't match current closing bracket, it's invalid
76//             if (top == -1 || stack[top] != c) {
77//                 return false;
78//             }
79//             top--; // Pop the stack
80//         }
81//     }
82
83//     // If top is -1, all brackets were matched correctly
84//     return top == -1;
85// }
86
87uint8_t open_or_close(char s)
88{
89    switch(s)
90    {
91        case '(':
92            return 1;
93        break;
94        case '{':
95            return 2;
96        break;
97        case '[':
98            return 3;
99        break;
100        case ')':
101            return 4;
102        break;
103        case '}':
104            return 5;
105        break;
106        case ']':
107            return 6;
108        break;
109        default:
110        break;
111    }
112    return 0;
113}
114
115bool isValid(char* s) {
116    bool retval;
117    uint32_t length = strlen(s);
118    if(( length == 0) || ( length == 1))
119    {
120        return false;
121        // nothing to compare
122    }
123    char buff[length];
124    uint8_t open = 0;
125    uint8_t close = 0;
126    uint32_t j = 0;
127    for(uint32_t i = 0; i<length; i++)
128    {
129        open = open_or_close(s[i]);
130        if(open<=3)
131        {
132            buff[j] = s[i];
133            j++;    
134        }
135        else
136        {
137            close = open;
138            if(j!=0)
139            {
140                j--;
141            }
142            open = open_or_close(buff[j]);
143            printf("open :%c close : %c", buff[j], s[i]);
144            if((open==1&&close==4)||(open==2&&close==5)||(open==3&&close==6))
145            {
146               retval = true;
147            }
148            else
149            {
150                retval = false;
151                return retval;
152            }
153            buff[j] = 0;
154        }
155    }
156    if(j>0)
157    {
158        retval = false;
159    }
160    return retval;
161}
162