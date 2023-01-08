/*
https://leetcode.com/problems/combination-sum-iii/
*/

class Solution {
public:
    vector<vector<int>> ans;

    void solve(int n,int j, int &sum, int k, vector<int> &temp){
        if(sum==n && temp.size()==k){
            ans.push_back(temp);
            return;
        }
        else if(sum>n || temp.size()>k) return;

        for(int i=j;i<10;i++){
            sum += i;
            temp.push_back(i);
            solve(n,i+1,sum,k,temp);
            sum -= i;
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        int sum=0;
        int j=1;
        solve(n,j, sum, k, temp);
        return ans;
    }
};
