/*
https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/
*/

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        unordered_map<int,pair<int,int>> mp; //(num, first occr, last occur)
        int ans = INT_MAX;
        
        for(int i=0; i<n; i++){
            if(mp.find(cards[i])==mp.end()){
                mp[cards[i]] = {i,i};
            }else{
                ans = min(ans, i - mp[cards[i]].second); //check with curr pair
                mp[cards[i]].second = i; //update first occr
            }
        }
      
        for(auto it: mp){
            if(it.second.second == it.second.first)
                continue;
            else
                ans = min(ans,(it.second.second - it.second.first));
        }

        return (ans==INT_MAX)? -1: ans+1;
    }
};
