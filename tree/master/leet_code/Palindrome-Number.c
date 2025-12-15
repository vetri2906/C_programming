1bool isPalindrome(int x) {
2
3    unsigned int reversed_val = 0;
4    unsigned int temp = x;
5
6    if (x < 0) {
7        return false;
8    } else {
9        while (temp > 0) {
10            reversed_val = (reversed_val * 10) + (temp % 10);
11            temp /= 10;
12        }
13        if (reversed_val != x) {
14            return false;
15        }
16    }
17    return true;
18}