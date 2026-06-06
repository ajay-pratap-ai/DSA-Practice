class Solution {
public:
    int search(vector<int>& nums, int target) {
        return newsearch(nums,0,nums.size()-1,target);
    }
    int newsearch(vector<int>&arr,int si , int ei,int target){
        if(si>ei) return -1;
        int mid = si + (ei-si)/2;
        if(arr[mid]==target) return mid;
        if(arr[si]<=arr[mid]){
            if(arr[si]<=target && target<=arr[mid]){
                return newsearch(arr,si,mid-1,target);
            }else {
               return  newsearch(arr,mid+1,ei,target);
            }
        }else{
             if(arr[mid]<=target && target<=arr[ei]){
               return  newsearch(arr,mid+1,ei,target);
            }else{
                return newsearch(arr,si,mid-1,target);
            }
        }
    }
};