/*
https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l=n-1, r=0;  // 1st wrong ind from direction
        
        stack<int> st1;
        for(int i=0; i<n; i++){
            while(!st1.empty() && nums[st1.top()] > nums[i]){
                l = min(st1.top(), l);
                st1.pop();
            }
            st1.push(i);
        }
        if(l==n-1) return 0; //already sorted

        stack<int> st2;
        for(int i=n-1; i>=0; i--){
            while(!st2.empty() && nums[st2.top()] < nums[i]){
                r = max(st2.top(), r);
                st2.pop();
            }
            st2.push(i);
        }

        return r-l+1;
    }
};


/* Monotonic Stack for (duplicates and more than one peak ) wont work
below solution only traverse till one peak arrived
it doesnt work for eg: 1,1,3,3,4,2,1
 ***therefore use stack of ind***
*/
