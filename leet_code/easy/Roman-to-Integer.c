1/******************************************************************************
2
3Welcome to GDB Online.
4  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
5  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
6  Code, Compile, Run and Debug online from anywhere in world.
7
8*******************************************************************************/
9#include <stdio.h>
10#include <string.h>
11
12int romanToInt(char* s) {
13	typedef struct {
14		char roman;
15		int num;
16	} int_roman_t;
17	int return_val = 0;
18	int previous_val = 0;
19	int_roman_t jump_table[7] = {
20		{ .roman = 'I', .num = 1},
21		{ .roman = 'V', .num = 5},
22		{ .roman = 'X', .num = 10},
23		{ .roman = 'L', .num = 50},
24		{ .roman = 'C', .num = 100},
25		{ .roman = 'D', .num = 500},
26		{ .roman = 'M', .num = 1000}
27	};
28	int len = strlen(s);
29	for (int loop = len; loop >= 0; loop--)
30	{
31		for (int loop2 = 0; loop2 < 7; loop2++)
32		{
33            // printf("s[0]] : %c\n", s[loop]);
34            // printf("roman[0] : %c\n", jump_table[loop2].roman);
35			if(s[loop] == jump_table[loop2].roman)
36			{
37				// printf("previous val : %d\n", previous_val);
38				if( jump_table[loop2].num >= previous_val)
39				{
40					return_val += jump_table[loop2].num;
41					previous_val = jump_table[loop2].num;
42					// printf("int val : %d\n", return_val);
43					break;
44				}
45				else
46				{
47					return_val -= jump_table[loop2].num;
48					// printf("int val else : %d\n", return_val);
49				}
50			}
51		}
52	}
53	// printf("return val : %d\n", return_val);
54	return return_val;
55}
56