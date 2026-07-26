class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int maxPro ;
        sort(nums.begin(),nums.end());
        int n = nums.size()-1;
        if(nums[0]>=0) {
            maxPro = nums[n]*nums[n-1]*nums[n-2];
            return maxPro;
        }
        if(nums[0]<0 ){
            maxPro = max(nums[n]*nums[n-1]*nums[n-2],nums[0]*nums[1]*nums[n]);
        }
        return maxPro ;
    }
};