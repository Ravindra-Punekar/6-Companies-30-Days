/*
15. Substrings containing all three Character
https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        unordered_map<char,int> mp;
              
        for(int l=0, r=0; r<n; r++){
            mp[s[r]]++; 

            while(mp['a']>0 && mp['b']>0 && mp['c']>0){
                ans += (n-r); 
                mp[s[l]]--;  // remove first char from win after counting
                l++; 
            }
        }

        return ans;
    }
};
