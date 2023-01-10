/*
https://leetcode.com/problems/factorial-trailing-zeroes/
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        
        while(n>1){
            n/=5;
            ans+=n;
        }

        return ans;
    }
};
