/*
https://leetcode.com/problems/ipo/
*/

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        
        vector<pair<int,int>> project;
        for(int i=0; i<n; i++){
            project.push_back({capital[i],profits[i]});
        }
        sort(project.begin(), project.end(),[&](pair<int,int> a,pair<int,int> b)
            { return (a.first==b.first)? a.second>b.second : a.first<b.first;});
        
        // for(auto p: project){
        //     cout<<p.first<<" "<<p.second<<endl;
        // }

        priority_queue<int>pq; 

        int i=0;
        while(k--){
            while(i<n && w >= project[i].first){
                pq.push(project[i].second);
                i++;
            }

            if(!pq.empty()){
                w += pq.top();
                pq.pop();
            }
            else break;
        }

        return w;

    }
};
