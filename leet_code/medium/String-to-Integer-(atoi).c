1#include <math.h>
2
3int check_leading_char_exceptions(char *s, int length, char c)
4{
5    for (int i = 0; i < length; i++)
6    {
7        if(s[i] != c)
8        {
9            return i;
10        }
11    }
12    return 0;
13}
14
15int myAtoi(char* s) {
16    long retval = 0;
17    int signedness = 0;
18    long negative_max_val = -1 *(pow(2, 31)); 
19    long positive_max_val =  pow(2, 31);
20    int length = strlen(s);
21    int start_val = check_leading_char_exceptions(s, length, ' ');
22    if(s[start_val] == 0x2d)
23    {
24        signedness = 1;
25        start_val++;
26        start_val += check_leading_char_exceptions(&s[start_val], length - start_val, '0');
27    }
28    else if (s[start_val] == 0x2b)
29    {
30        start_val++;
31    }
32
33    for (int i = start_val; i < length; i++)
34    {
35        if(s[i] >= 48 && s[i]<= 57)
36        {
37            if(positive_max_val <= (retval*10)+ (s[i]-48))
38            {
39                if (!signedness)
40                {
41                    retval = positive_max_val -1;
42                }
43                else
44                {
45                    retval = positive_max_val;
46                }
47            } 
48
49            else
50            {
51                retval= (retval*10)+ (s[i]-48);
52            }
53        }
54        else
55        {
56            break;
57        }
58    }
59    if (signedness)
60    {
61        retval = (retval*(-1));
62    }
63    return retval;
64}