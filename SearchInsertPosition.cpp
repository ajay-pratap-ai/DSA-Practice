class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return search(nums, 0, nums.size() - 1, target);
    }

    int search(vector<int>& nums, int si, int ei, int target) {
        if (si > ei) return si;

        int mid = si + (ei - si) / 2;

        if (nums[mid] == target)
            return mid;

        if (nums[mid] > target)
            return search(nums, si, mid - 1, target);

        return search(nums, mid + 1, ei, target);
    }
};