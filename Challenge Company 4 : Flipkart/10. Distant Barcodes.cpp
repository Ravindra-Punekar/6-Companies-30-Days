/*
https://leetcode.com/problems/distant-barcodes/
*/

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> mp;
        int n = barcodes.size();
        vector<int> ans(n,0);

        for(auto b:barcodes)
            mp[b]++;
        
        priority_queue<pair<int,int>> pq;

        for(auto& it:mp)
            pq.push({ it.second, it.first});

        int i=0, j=1;

        while(pq.size()){
            auto curr = pq.top();     pq.pop();
            
            while(curr.first  ){
                ans[i]= curr.second;
                i+=2;
                curr.first--;
                if(i>=n){
                    i=1;
                }
            }
        } 

        return ans;
    }
};
