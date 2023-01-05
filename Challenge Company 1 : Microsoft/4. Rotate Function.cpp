/*
https://leetcode.com/problems/rotate-function/
*/

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int maxVal =0;
        int sum=0;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            sum += nums[i];
            maxVal += i*nums[i];
        }

        int prev = maxVal;
       
        for(int i=0; i<n; i++){
            prev = prev + sum - n*nums[n-i-1];
            maxVal = max(maxVal,prev);
        }

        return maxVal;
    }
};
