/*
https://leetcode.com/problems/custom-sort-string/
*/

class Solution {
public:
    string customSortString(string order, string s) {
        string ans;
        unordered_map<char,int> mp;

        for(auto ch:s)
            mp[ch]++;

        for(auto ch:order){
            if(mp.count(ch)){
                ans.insert(ans.end(),mp[ch], ch);
                mp.erase(ch);
            }
        }

        for(auto it:mp){
            ans.insert(ans.end(),it.second, it.first);
        }
        return ans;
    }
};
