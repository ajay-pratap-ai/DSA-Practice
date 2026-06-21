class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;

        long long s = 1;

        while (s < n) {
            s *= 2;
        }

        return s == n;
    }
};