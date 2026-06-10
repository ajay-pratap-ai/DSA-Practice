class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        return ques(arr,0,arr.size()-1);
    }
    int ques(vector<int>&arr,int si,int ei){
        int mid = si + (ei-si)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            return mid;
        }
        if(arr[mid]>arr[mid+1] && arr[mid]<arr[mid-1]){
            return ques(arr,si,mid);
        }if(arr[mid]<arr[mid+1] && arr[mid]>arr[mid-1]){
           return ques(arr,mid+1,ei);
        }
        return -1;
    }
};