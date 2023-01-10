/*
https://leetcode.com/problems/count-nice-pairs-in-an-array/
*/

class Solution {
public:
   
    int rev(int n){
        int x=0;
        while(n>0){
            x += n%10;
            if(n>=10)    x*=10;
            n /=10;
        }
        return x;
    }

    int countNicePairs(vector<int>& nums) {
        /*      a + rev(b) = rev(a) + b 
            =>  a - rev(a) = b - rev(b)         */
        
        int MOD = 1e9+7;
        int count=0;
        int n = nums.size();
        
        unordered_map<int,int> mp;
        vector<int> diff; 
        
        for(auto i:nums){
            int t=i-rev(i);
            mp[(t)]++;
            diff.push_back(t); 
        }

        for(int i=0; i<n; i++){
            if(mp[diff[i]]>1){
                count = (count + mp[diff[i]]-1)%MOD;
                mp[diff[i]]--;
            }
        }

        return count;
    }
};
