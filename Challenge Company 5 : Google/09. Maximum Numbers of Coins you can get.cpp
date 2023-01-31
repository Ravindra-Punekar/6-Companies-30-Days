/*
https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
*/

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int coins =0;
        sort(piles.begin(), piles.end());
        
        int k=piles.size()/3;
        
        int i=piles.size()-2;
        
        while(k--){
            coins += piles[i];
            i-=2;
        }

        return coins;
    }
};
