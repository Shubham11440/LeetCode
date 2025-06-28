class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();

        // Skip leading whitespaces
        while (i < n && s[i] == ' ') i++;

        // Edge case: empty or all spaces
        if (i == n) return 0;

        // Check for sign
        int sign = 1;
        if (s[i] == '+' || s[i] == '-') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        long ans = 0;
        int MAX = INT_MAX, MIN = INT_MIN;

        // Process digits
        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');

            // Clamp to INT range
            if (sign == 1 && ans > MAX) return MAX;
            if (sign == -1 && -ans < MIN) return MIN;
            i++;
        }

        return static_cast<int>(sign * ans);
    }
};
