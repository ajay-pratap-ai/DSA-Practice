class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = nums[0] ;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum = sum + nums[i];
            maxSub = max(sum,maxSub);
            if(sum<0) sum=0;
        }
        return maxSub;

    }
};