class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int start = 0;
        int last = 0;
        int j = 0;
        vector<int>ans;
        sort(nums.begin(),nums.end());
        for(int i = nums[0];i<nums.size()+nums[0]-1;i++){
            if(nums[j+1] != nums[j]+1){
                start = nums[j];
                last = nums[j+1];
                 for(int i=start+1;i<last;i++){
                 ans.push_back(i);
                }
            }
            j++;
        }
        return ans;
    }
};