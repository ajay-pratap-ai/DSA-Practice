class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        ms(nums,0,nums.size()-1);
        return nums ;
    }
    void merge(vector<int>& arr,int si,int mid,int ei){
        vector<int>temp;
        int i = si;
        int j = mid+1;
        while(i<=mid && j<=ei){
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i++]);
            }else{
                temp.push_back(arr[j++]);
            }
        }
        while(i<=mid){
            temp.push_back(arr[i++]);
        }
        while(j<=ei){
            temp.push_back(arr[j++]);
        }
        for(int i=si,x=0;i<=ei;i++){
            arr[i]=temp[x++];
        }
    }
    void ms(vector<int>&arr,int si,int ei){
        if(si>=ei) return;
        int mid = si + (ei-si)/2;
        ms(arr,si,mid);//left
        ms(arr,mid+1,ei);//right
        merge(arr,si,mid,ei);
    }
};