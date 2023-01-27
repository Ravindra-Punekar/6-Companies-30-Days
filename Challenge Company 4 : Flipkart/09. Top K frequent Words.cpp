/*
https://leetcode.com/problems/top-k-frequent-words/
*/

class Solution {
public:
    static bool cmp(pair<string, int>& a, pair<string, int>& b){
        return (a.second == b.second)? (a.first < b.first) : (a.second > b.second);
    }
 
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        map<string , int> mp;

        for(auto s:words)
            mp[s]++;
        
        vector<pair<string, int>> temp;
 
        for (auto& it : mp) 
            temp.push_back(it);
        
        sort(temp.begin(), temp.end(), cmp);
        
        for(int i=0;i<k;i++)
            ans.push_back({temp[i].first});
        
        return ans;
    }
};
