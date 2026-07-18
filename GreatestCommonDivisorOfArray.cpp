class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maximum = INT_MIN;
        int minimum = INT_MAX;
        for(int i=0;i<nums.size();i++){
            maximum = max(maximum,nums[i]);
            minimum = min(minimum,nums[i]);    
        }
        int g = gcd(maximum,minimum);
        return g;
    } 
};