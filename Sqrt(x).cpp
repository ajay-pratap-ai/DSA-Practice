class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;

        int low = 1, high = x;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (mid <= x / mid) {
                ans = mid;        // Possible answer
                low = mid + 1;    // Try to find a larger one
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};