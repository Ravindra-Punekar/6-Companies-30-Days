/*
https://leetcode.com/problems/sort-an-array/
*/

class Solution {
public:
    void merge(vector<int>& nums, int s, int mid, int e){
        vector<int> merged(e-s+1, 0);

        int ind1 = s;
        int ind2 = mid+1;
        int k=0;

        while(ind1<=mid && ind2<= e){
            if(nums[ind1] <nums[ind2])
                merged[k++] = nums[ind1++];
            else
                merged[k++] = nums[ind2++];
        }

        while(ind1<=mid)
            merged[k++] = nums[ind1++];
        
        while(ind2<=e)
            merged[k++] = nums[ind2++];
        
        for(int i=0; i<merged.size(); i++)
            nums[i+s] = merged[i];
    }

    void mergeSort(vector<int>& nums, int s, int e){
        if(s>=e) return;
        int mid = s + (e-s)/2;

        mergeSort(nums, s, mid);
        mergeSort(nums, mid+1, e);

        merge(nums, s, mid,  e);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        return nums;
    }
};
