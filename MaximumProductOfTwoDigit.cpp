class Solution {
public:
    int maxProduct(int n) {
        vector<int>nums;
        int s = 0;
        while(n>0){
            s = n%10;
            nums.push_back(s);
            n = n/10;
        }
        int maxPro = INT_MIN;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                maxPro = max(maxPro,nums[i]*nums[j]);
            }
        }
        return maxPro;
    }
};