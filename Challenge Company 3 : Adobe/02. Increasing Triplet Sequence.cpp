/*
https://leetcode.com/problems/increasing-triplet-subsequence/
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n1 = INT_MAX, n2 = INT_MAX;
        for(auto n3: nums)
            if(n3<=n1) n1 = n3;
            else if(n3<=n2) n2 = n3;
            else return true;
        return false;
    }
}; 
