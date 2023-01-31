/*
https://leetcode.com/problems/matrix-block-sum/
*/

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));

        vector<vector<int>> preSum(n+1,vector<int>(m+1,0));
        
        // prefix Sum of 2D matrix //IMP 
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                preSum[i][j] += ( mat[i-1][j-1] + preSum[i-1][j] 
                                + preSum[i][j-1] - preSum[i-1][j-1]);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x1 = max(0,i-k); 
                int y1 = max(0,j-k);
                int x2 = min(n,i+k+1);
                int y2 = min(m,j+k+1);
                ans[i][j] = preSum[x2][y2] + preSum[x1][y1] 
                            - preSum[x1][y2] - preSum[x2][y1];
            }
        }

        return ans;
    }
};
