/*
https://leetcode.com/problems/maximum-compatibility-score-sum/
*/

class Solution {
public:
    void solve(vector<vector<int>>& s, vector<vector<int>>& m,vector<bool> vis, int ind, int score, int& ans){
        if(ind >= s.size()) {
            ans = max(ans, score);
            return;
        }
        int n = s.size();
        int compScore=0;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                vis[i] = true;
                int cnt=0;
                for(int k=0; k<s[0].size(); k++){
                    if(s[ind][k] == m[i][k]){
                        cnt++;
                    }
                }
                compScore = cnt;
                solve(s, m, vis, ind+1, score+compScore, ans);
                vis[i] = false; 
            }
        }
        
    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int ans=0;
        int n = students.size();
        vector<bool> vis(n,false);
        int ind=0, score = 0;
        solve(students, mentors, vis, ind, score, ans);
        return ans;
    }
};
