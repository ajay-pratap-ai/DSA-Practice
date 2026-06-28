class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(vector<int>& nums, int index) {
        ans.push_back(temp);

        for (int i = index; i < nums.size(); i++) {
            temp.push_back(nums[i]);      // Choose
            solve(nums, i + 1);           // Explore
            temp.pop_back();              // Backtrack
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums, 0);
        return ans;
    }
};