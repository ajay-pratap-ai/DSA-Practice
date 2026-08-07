class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size(), sign = 1;
        long long ans = 0;

        // Skip spaces
        while (i < n && s[i] == ' ')
            i++;

        // Check sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Overflow check
            if (ans > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            ans = ans * 10 + digit;
            i++;
        }

        return sign * ans;
    }
};